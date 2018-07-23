import cPickle as pickle
import shakespeareRetrieve as sk
import evalExpression as evl
import collectingSpeech as cs


def calc_res(post_expr, csr, all_doc_ids):
    stack_r = list()
    for w in post_expr:
        if w == 'and' or w == 'or':
            oprand1 = stack_r.pop()
            oprand2 = stack_r.pop()
            if type(oprand1) is not set:
                oprand1 = csr[oprand1]
            if type(oprand2) is not set:
                oprand2 = csr[oprand2]
            res_tmp = set()
            if w == 'and':
                res_tmp = oprand1 & oprand2
            else:
                res_tmp = oprand1 | oprand2
            stack_r.append(res_tmp)
        elif w == 'not':
            oprand = stack_r.pop()
            if type(oprand) is not set:
                oprand = csr[oprand]
            res_tmp = set(all_doc_ids) - oprand
            stack_r.append(res_tmp)
        else:
           stack_r.append(w.lower())
    res = stack_r.pop()
    return res


def parseExpr(expr):
    lexpr = expr.split(' ')
    for idx in xrange(len(lexpr)):
        if lexpr[idx] == 'left':
            lexpr[idx] = '('
        elif lexpr[idx] == 'right':
            lexpr[idx] = ')'
    return lexpr


if __name__ == "__main__":

    option = raw_input("do you want to update the dictionary before we started?[yes/no]")
    while option !='yes' and option != 'no':
        option = raw_input("do you want to update the dictionary before we started?[yes/no]")
    
    csr = {}
    all_doc_ids = []
    doc_list = sk.make_doc_list('ShakesPeare/')
    if option == 'yes':    
        # rebuild the inverted index table
        docs_in_words = sk.all_docs_in_words(doc_list)
        csr, all_doc_ids = sk.build_csr(docs_in_words)
        with open('dictionary.p', 'wb') as f:
            pickle.dump(csr, f)
        with open('all_doc_ids.p', 'wb') as f:
            pickle.dump(all_doc_ids, f)
    else:
        with open('dictionary.p', 'rb') as f:
            csr = pickle.load(f)
        with open('all_doc_ids.p', 'rb') as f:
            all_doc_ids = pickle.load(f)
    
    option = raw_input("are you ready to start?[yes/no]")
    while option != 'yes' and option != 'no':
        option = raw_input("do you want to start to query?[yes/no]")    
    if option == 'yes':
        while True:
            # collecting sound
            expr = cs.Houndify_collect()
            lexpr = parseExpr(expr)

            print "is this the expression you mentioned? "
            print lexpr
            option = raw_input("type in [yes/no]")
            while option != "yes" and option != "no":
                option = raw_input("type in [yes/no]")
        
            # if the user says that Houndify failed to recognize his/her sound
            if option == "no":
                expr = raw_input("please input your query expression here: ")
                lexpr = expr.split(' ')
                print lexpr
        
            # generate postfix expression
            post_expr = evl.generatePostExpression(lexpr)
        
            # calculate the query result
            res = calc_res(post_expr, csr, all_doc_ids)
            print "books that satisfy: "
            for f in res:
                print doc_list[f]
        
            # ask user if he/she wants to do another query
            option = raw_input("another query ? [yes/no]")
            while option != "yes" and option != "no":
                option = raw_input("another query? [yes/no]")
            if option == "no":
                break
