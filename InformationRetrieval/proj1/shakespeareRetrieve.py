import re
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
    res = []
    for f in file_list:
        with open(f, 'r') as doc:
            doc_in_string = doc.read()
            doc_in_list = re.findall(r"\w+", doc_in_string)
            res.append(doc_in_list)
    return res


"""
step 3: build the csr table for retrieval
@param work_in_words: all words from all the documents in the form of list 
"""


def build_csr(work_in_words):
    res = {}
    num = len(work_in_words)
    for book_idx in xrange(num):
        for word in work_in_words[book_idx]:
            if word.lower() in res:
                res[word.lower()].add(book_idx)
            else:
                res[word.lower()] = set()
                res[word.lower()].add(book_idx)
    return res, list(range(num))


"""
functionality(and, or, not):
@param a: the first input word
@param b: the second input word
@param csr_table: the csr table we just build
@param all_doc_id: all document id in a list



def doing_and(a, b, csr_table):
    a_doc = csr_table[a]
    b_doc = csr_table[b]
    return a_doc & b_doc


def doing_or(a, b, csr_table):
    a_doc = csr_table[a]
    b_doc = csr_table[b]
    return a_doc | b_doc


def doing_not(a, csr_table, all_doc_id):
    a_doc = csr_table[a]
    return set(all_doc_id) - a_doc
    
"""


"""
doc_list = make_doc_list('ShakesPeare/')
docs_in_words = all_docs_in_words(doc_list)
csr = build_csr(docs_in_words)
and_res = doing_and('woods', 'originality', csr)
print and_res
"""
