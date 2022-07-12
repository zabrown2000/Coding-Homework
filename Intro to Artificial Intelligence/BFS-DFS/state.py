'''
The state is a list of 2 items: the board, the path
The target is :
012
345
678

'''
import random
import math
def get_next(x): #receives state and performs all possible actions on state and then inserts them into the frontier
    ns=[]
    for i in "<>v^":
        s=x[0][:] #: means everything in that row all the numbers in list of board,
                #here s is something removes from frontier, list of #s + atring of actions
        if_legal(s,i)
        if s.index(0)!=x[0].index(0) and \
           (x[1]=="" or x[1][-1]!="><^v"["<>v^".index(i)]):
            ns.append([s,x[1]+i])
    return ns

#returns a random board nXn
def create(n):
    s=list(range(n*n)) #create list in range nxn
    m="<>v^"
    for i in range(n**3):
        if_legal(s,m[random.randrange(4)]) #randomly chooses 1 of 4 actions and does it n^3 times, until it's all messed up, working backwords from goal state
        #can add some line here or in ifLegal to see if a move was executed, it'll return it. Because could be shorter way to solve than how made it
    return [s,""] #returning randomized string along with empty path, will be adding to string as get closer to goal state
    #work backwords so that way know board is solvable

def path_len(x):
    return len(x[1])

def is_target(x):
    n=len(x[0])
    return x[0]==list(range(n))

def hdistance(s):
    return 0

#############################
def if_legal(x,m): #checks that each move can be done
    n=int(math.sqrt(len(x)))
    z=x.index(0)
    if z%n>0 and m=="<":
        x[z]=x[z-1]
        x[z-1]=0
    elif z%n<n-1 and m==">":
        x[z]=x[z+1]
        x[z+1]=0
    elif z>=n and m=="^":
        x[z]=x[z-n]
        x[z-n]=0
    elif z<n*n-n and m=="v":
        x[z]=x[z+n]
        x[z+n]=0

