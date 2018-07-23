import sys
import Tida


if __name__=="__main__":
    option = input("do you want to start query session?[y/n]")
    while option!='y' and option!='n':
        option = input("do you want to start query session?[y/n]")
    while option == 'y':
        td = Tida.Tida(False)
        queryStr = input("pls now input your query!")
        td.query(queryStr)
        option = input("do you want to do another query session?[y/n]")

