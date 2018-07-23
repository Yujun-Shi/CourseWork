# whoosh utils
from whoosh import index
from whoosh import scoring
import whoosh.qparser as qparser
from whoosh.qparser import QueryParser


# build in utils
import os
import urllib
from urllib.parse import urljoin
import _pickle as pickle
import operator
import re

# html utils
from bs4 import BeautifulSoup as bSoup
from bs4.element import Comment

# calculate utils
from scipy.sparse import csr_matrix
import numpy as np

# shiyujun utils
from TidaSchema import TidaSchema as tds
from pageRank import pageRanker



class Tida:

    def __init__(self, rebuild = False, dataDir_ = "../data", 
                 indexDir_ = "../index", alpha_ = 0.85):
        """
        initialize indexer
        """
        if rebuild:
            if not os.path.isdir(dataDir_):
                os.makedirs(dataDir_) 
            if not os.path.isdir(indexDir_):
                os.makedirs(indexDir_)

            self.alpha = alpha_
            self.indexDir = indexDir_
            self.dataDir = dataDir_
            #exists = index.exists_in(self.indexDir)
            #if (not exists) or rebuild:
            self.indexer = index.create_in(self.indexDir, tds)
            #else:
            #    self.indexer = index.open_dir(self.indexDir)
            self.allFilesMap = self.__collectAllFiles()
            self.hrefMap = {}
            self.anchorTextMap = {}
            self.__extractAllInfo()
            self.__saveAllData()
        else:
            try:
                self.indexer = index.open_dir(indexDir_)
                with open('allFilesMap.p','rb') as f:
                    self.allFilesMap = pickle.load(f)
                with open('pgrank.p', 'rb') as f:
                    self.pgrank = pickle.load(f)
            except:
                print("you obviously have to rebuild the whole damn thing!")
    """
    indexer untils
    """
    def __collectAllFiles(self):
        map_ = {}
        i = 0
        with open('records.txt','w') as f:
            for root, dirs, files in os.walk(self.dataDir):
                for file_ in files:
                    try:
                        filePath = os.path.join(root, file_)
                        filePath = filePath[1+len(self.dataDir):]
                        # test if correctly encoded
                        f.write(filePath)
                        
                        map_[filePath] = i
                        i = i + 1
                        
                    except:
                        pass
        print(str(i) + " records in total!")
        return map_

    # used to extract anchor text and get hrefMap
    def __linkPreAnalysis(self):
        # initialize self.hrefMap and self.anchorTextMap
        for file_ in self.allFilesMap:
            self.hrefMap[file_] = []
            self.anchorTextMap[file_] = []
            # use the URL itself as an anchorText
            self.anchorTextMap[file_].append(file_) 
        
        for file_ in self.allFilesMap:
            with open(os.path.join(self.dataDir, file_), 'r') as fopen_:
                # check if actually parsable
                try:
                    soup = bSoup(fopen_, 'lxml')
                except:
                    continue
                
                for working in soup.findAll('a', href=True):
                    fullUrl = urljoin(file_, working['href'])
                    
                    # check if the url actually exists
                    if fullUrl in self.allFilesMap:
                        # put link in
                        self.hrefMap[file_].append(fullUrl)
                        
                        # put anchor text in
                        self.anchorTextMap[fullUrl].append(working.getText())


    def __extractAllInfo(self):

        self.__linkPreAnalysis()

        csrRow = []
        csrCol = []
        csrVal = []
        csrRow.append(len(csrCol))
        
        writer = self.indexer.writer() 
        for file_ in self.allFilesMap:
            with open(os.path.join(self.dataDir, file_), 'r') as fopen_:
                visiText = ""
                pageTitle = ""
                """
                if it's a html, analyze it and extract 
                visible text
                """
                try:
                    soup = bSoup(fopen_, 'lxml')
                    for script in soup(["script", "style"]):
                        script.extract()
                    # extract pageTitle      
                    visiText = soup.get_text()
                    lines = (line.strip() for line in visiText.splitlines())
                    chunks = (phrase.strip() for line in lines for phrase in
                            line.split(" "))
                    visiText = ''.join(chunk for chunk in chunks if chunk)
                    pageTitle = soup.title.string 
                except Exception as e:
                    pass

                hrefList_ = self.hrefMap[file_]
                
                """
                file in laplacian
                """
                if len(hrefList_) != 0:
                    tmpVal = [1.0 / len(hrefList_)] * len(hrefList_)
                    tmpCol = []
                    for link_ in hrefList_:
                        """
                        test if the link actually exists
                        in the result we get
                        actually, it should be fine since
                        we've already checked it before
                        """
                        try:
                            tmpCol.append(self.allFilesMap[link_])
                        except:
                            pass

                    csrVal.extend(tmpVal)
                    csrCol.extend(tmpCol)
                    csrRow.append(len(csrCol))
                else:
                    csrRow.append(len(csrCol))
                
                try:
                    pageTitle = self.__cleanhtml(pageTitle)
                except:
                    pageTitle = ""
                    print("error title: " + file_)
                tmp = ''.join(self.anchorTextMap[file_])
                writer.add_document(pageURL=file_, fullText=visiText, 
                                    anchorText=tmp,
                                    title=pageTitle)
        writer.commit()
        """
        obtain laplacian matrix
        """
        csrRow = np.array(csrRow)
        csrCol = np.array(csrCol)
        csrVal = np.array(csrVal)
        lap = csr_matrix((csrVal, csrCol, csrRow),
                          shape=(csrRow.shape[0]-1, csrRow.shape[0]-1),
                          dtype=np.float32)
        
        self.ranker = pageRanker(self.alpha, lap) 
        # do page rank
        self.pgrank = self.ranker.rankRes()
    
    def __saveAllData(self):
        with open('allFilesMap.p','wb') as f:
            pickle.dump(self.allFilesMap, f)
        with open('pgrank.p','wb') as f:
            pickle.dump(self.pgrank, f)

    def __cleanhtml(self, raw):
        cleaner = re.compile('<.*?>')
        cleantext = re.sub(cleaner, '', raw)
        cleantext = cleantext.strip()
        cleantext = cleantext.replace('\n','')
        cleantext = cleantext.replace('\t','')
        cleantext = cleantext.replace('\r','')
        return cleantext

    def query(self, q):
        # parser
        qpcontent = QueryParser("fullText", schema=self.indexer.schema)
        qpanchor = QueryParser("anchorText", schema=self.indexer.schema)
        qpcontent.add_plugin(qparser.OperatorsPlugin())
        qpanchor.add_plugin(qparser.OperatorsPlugin())
        # query
        qcontent = qpcontent.parse(q)
        qanchor = qpanchor.parse(q)
        resWeb = []
        with self.indexer.searcher() as s:
            resContent = s.search(qcontent, limit=40)
            resAnchor = s.search(qanchor, limit=40)
            resFinal = resAnchor
            resFinal.upgrade_and_extend(resContent)
            
            respgMap = {}
            resAnchorMap = {}
            resTextMap = {}
            resURLMap = {}
            
            for r in resFinal:
                resURLMap[r['pageURL']] = r
            for r in resFinal:
                respgMap[r['pageURL']]=self.pgrank[self.allFilesMap[r['pageURL']]]
                resAnchorMap[r['pageURL']]=r['anchorText']
                resTextMap[r['pageURL']]=r['fullText']
            
            supportedRes = []
            for r in respgMap:
                supportedRes.append((r, respgMap[r]))
            
            # consolidate the result by VSMSP algorithm
            ii = 0
            while ii + 10 < len(supportedRes):
                supportedRes[ii:ii+10] = sorted(supportedRes[ii:ii+10],
                                                key=operator.itemgetter(1))
                ii = ii + 10
            
            supportedRes[ii:] = sorted(supportedRes[ii:],
                                       key=operator.itemgetter(1))

            for r in supportedRes:
                hts = self.__cleanhtml(resURLMap[r[0]].highlights("anchorText",top=3))
                hts = hts + self.__cleanhtml(resURLMap[r[0]].highlights("fullText",top=2))
                resWeb.append([resURLMap[r[0]]["title"], r[0], hts])
                """
                print(resURLMap[r[0]]["title"])
                print(r[0])
                print(r[1])
                print(self.__cleanhtml(resURLMap[r[0]].highlights("anchorText",top=3)))
                print(self.__cleanhtml(resURLMap[r[0]].highlights("fullText",top=2)))
                print("\n\n\n")
                """ 
            
        return resWeb


