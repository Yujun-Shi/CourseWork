import cPickle as pickle
import academicRetrieval as ac
import doQuery as dq
import collectingSpeech as cs


if __name__ == "__main__":

    option = raw_input("do you want to update the dictionary before we started?[yes/no]")
    while option != 'yes' and option != 'no':
        option = raw_input("do you want to update the dictionary before we started?[yes/no]")
    
    tfidf = {}
    norms = {}
    doc_list = ac.make_doc_list('papers/')
    if option == 'yes': 
        #rebuild the table
        docs_in_words = ac.all_docs_in_words(doc_list)
        tf, docf = ac.build_ftable(docs_in_words)
        norms = ac.cvt_tf(tf)
        
        #save the data
        with open('tf.p', 'wb') as f:
            pickle.dump(tfidf, f)
        with open("norms.p", 'wb') as f:
            pickle.dump(norms, f)
    else:
        with open('dictionary.p', 'rb') as f:
            tfidf = pickle.load(f)
        with open("norms.p", 'wb') as f:
            norms = pickle.load(f)
    
    option = raw_input("are you ready to start?[yes/no]")
    while option != 'yes' and option != 'no':
        option = raw_input("do you want to start to query?[yes/no]")    
    if option == 'yes':
        while True:
            # collecting sound
            query = cs.Houndify_collect()
            query_vec = query.split(' ');
            print "is this the query you mentioned? "
            print query
            option = raw_input("type in [yes/no]")
            while option != "yes" and option != "no":
                option = raw_input("type in [yes/no]")
        
            # if the user says that Houndify failed to recognize his/her sound
            if option == "no":
                query = raw_input("please input your query expression here: ")
                query_vec = query.split(' ')
            
            # get the k
            k = input("how many results do you actually want?")
            
            # calculate the query result
            res = dq.getKNNRes(k, query_vec, tfidf, docf, norms)
            print res
            
            # ask user if he/she wants to do another query
            option = raw_input("another query ? [yes/no]")
            while option != "yes" and option != "no":
                option = raw_input("another query? [yes/no]")
            if option == "no":
                break
