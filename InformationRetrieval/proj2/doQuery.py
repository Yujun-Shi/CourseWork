import math


def process_query(query_vec, docf, num_doc):
    query_weight = {}
    for word in query_vec:
        if word in query_weight:
            query_weight[word] += 1.0
        else:
            query_weight[word] = 1.0
    for word in query_weight:
        if word in docf:
            query_weight[word] = (1.0+math.log(query_weight[word]))*math.log(num_doc/docf[word])
    return query_weight

def calc_dot(query_weight, doc_weight):
    dot_product = 0.0;
    for word in query_weight:
        if word in doc_weight:
            dot_product += query_weight[word]*doc_weight[word];
    return dot_product

def calc_res(query_vec, tf, docf, norms):
    res_all = {}
    query_weight = process_query(query_vec, docf, len(tf))
    for doc in tf:
        dot_product = calc_dot(query_weight, tf[doc])
        res = dot_product / norms[doc]
        res_all[doc] = res
        
    return res_all

def getKNNRes(k, query_vec, tfidf, docf, norms):
    res_all = calc_res(query_vec, tfidf, docf, norms)
    knn_res = []
    for i in xrange(k):
        maxDoc = max(res_all, key = res_all.get)
        knn_res.append(maxDoc)
        res_all.pop(maxDoc)
    return knn_res

