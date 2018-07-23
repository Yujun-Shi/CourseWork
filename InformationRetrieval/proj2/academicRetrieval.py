import re
import math
from os import listdir
from os.path import isfile, join

"""
step 1: build the document list
@param dir_path: the directory of a set of files
"""


def make_doc_list(dir_path):
    file_list = [(dir_path + f) for f in listdir(dir_path) if isfile(join(dir_path, f))]
    return file_list


"""
step 2: read in files and separate all words
@param file_list: a list of files to read and process
"""


def all_docs_in_words(file_list):
    res = {}
    for f in file_list:
        with open(f, 'r') as doc:
            doc_in_string = doc.read()
            doc_in_list = re.findall(r"\w+", doc_in_string)
            res[doc.name] = doc_in_list
    return res


"""
step 3: build the csr table for retrieval
@param work_in_words: all words from all the documents in the form of list 
"""


def build_ftable(work_in_words):
    tftable = {}
    docftable = {}
    book_idx = 0
    for book_name in work_in_words:
        for word in work_in_words[book_name]:
            word = word.lower()
            if book_name in tftable:
                if word in tftable[book_name]:
                    tftable[book_name][word] += 1.0
                else:
                    tftable[book_name][word] = 1.0
            else:
                tftable[book_name] = {}
                tftable[book_name][word] = 1.0;

            if word in docftable:
                docftable[word].add(book_idx)
            else:
                docftable[word] = set()
                docftable[word].add(book_idx)
        book_idx += 1

    for word in docftable:
        docftable[word] = len(docftable[word])
    
    return tftable, docftable


def cvt_tf(tftable):
    norms = {}
    for book_name in tftable:
        norms[book_name] = 0.0;
        for word in tftable[book_name]:
            tftable[book_name][word] = 1.0 + math.log10(tftable[book_name][word]);
            norms[book_name] += tftable[book_name][word] ** 2
        norms[book_name] = math.sqrt(norms[book_name]);
    return norms

if __name__ == "__main__":
    doc_list = make_doc_list('ShakesPeare/')
    docs_in_words = all_docs_in_words(doc_list)
    tf, docf = build_ftable(docs_in_words)
    cvt_tf_idf(tf, docf, len(doc_list))

    print doc_list
    print tf

