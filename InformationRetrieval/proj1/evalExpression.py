def preSmall(oper1, oper2):
    if oper1 == 'not':
        return False
    elif oper1 == 'and':
        if oper2 == 'not':
            return True
        else:
            return False
    elif oper1 == 'or':
        if oper2 != 'or':
            return True
        else:
            return False
    else:
        print oper1
        print oper2
        raise ValueError("operator has to be 'or', 'not' or 'and'");


def generatePostExpression(lexpr):

    res = list()
    stack_p = list()
    for w in lexpr:
        if w == '(':
            stack_p.append(w)
        elif w == ')':
            oper = stack_p.pop()
            while oper != '(':
                res.append(oper)
                oper = stack_p.pop()

        elif (w == "and") or (w == "or") or (w == "not"):
            if (not stack_p) or stack_p[-1] == '(':
                stack_p.append(w)
            else:
                while stack_p and stack_p[-1] != '(' and preSmall(w, stack_p[-1]):
                    oper = stack_p.pop()
                    res.append(oper)
                stack_p.append(w)
        else:
            res.append(w)

    while stack_p:
        oper = stack_p.pop()
        res.append(oper)

    return res

"""
expression = "not ( a and b ) or c"
postExp = generatePostExpression(expression)
print postExp
"""
