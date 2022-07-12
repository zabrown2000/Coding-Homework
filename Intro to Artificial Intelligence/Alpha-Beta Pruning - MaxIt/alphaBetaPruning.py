'''
ttt is a solved game-know a winning strategy or know that no exist winning str,
case for this game because we know how to play and computer knows all
tricks as well

It is common knowledge that the best opening move is choosing the
middle square. Why does the computer choose the top-left square for
depth 9, but chooses the middle square for depth 2?
--not true! there are stupid moves, but no big advt to mid square over corner
'''

import game
import copy
DEPTH = 10
#depth works with heuristic function->d in abmin/max, quicker with =2
def go(s):
    if game.isHumTurn(s):
        return abmin(s,DEPTH,float("-inf"),float("inf"))[1]
    else:
        return abmax(s,DEPTH,float("-inf"),float("inf"))[1]

#s = the state (max's turn)
#d = max. depth of search
#a,b = alpha and beta
#returns [v, ns]: v = state s's value. ns = the state after recomended move.
#        if s is a terminal state ns=0.
def abmax(s,d,a,b):
    if d==0 or game.isFinished(s):
        return [game.value(s),0]
    v=float("-inf")
    ns=game.getNext(s)
    bestMove=0
    for i in ns:
        tmp=abmin(copy.deepcopy(i),d-1,a,b) #deep copy because then pointing to same thing (like in c++), don't want a shallow copy
        if tmp[0]>v:
            v=tmp[0]
            bestMove=i
        if v>=b:
            return [v,i]
        if v>a:
            a=v
    return [v,bestMove]

#s = the state (min's turn)
#d = max. depth of search
#a,b = alpha and beta
#returns [v, ns]: v = state s's value. ns = the state after recomended move.
#        if s is a terminal state ns=0.
def abmin(s,d,a,b):
    if d==0 or game.isFinished(s):
        return [game.value(s),0]
    v=float("inf")
    ns = game.getNext(s)
    bestMove=0
    for i in ns:
        tmp = abmax(copy.deepcopy(i), d - 1, a, b)
        if tmp[0]<v:
            v = tmp[0]
            bestMove = i
        if v <=a:
            return [v,i]
        if v <b:
            b = v
    return [v, bestMove]
'''
s=game.create()
game.makeMove(s,1,1)
print(s)
game.makeMove(s,0,0)
game.makeMove(s,0,1)
game.makeMove(s,0,2)
game.makeMove(s,1,0)
game.makeMove(s,1,1)
game.makeMove(s,1,2)
game.makeMove(s,2,1)
game.makeMove(s,2,0)
game.printState(s)
print(go(s))
'''
