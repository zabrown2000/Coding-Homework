#like main file

import alphaBetaPruning
import game

board=game.create()
game.whoIsFirst(board)
while not game.isFinished(board):
    if game.isHumTurn(board):
        game.inputMove(board)
    else:
        board=alphaBetaPruning.go(board)
game.printState(board)

'''
Notes from ppt:
hur = #x sequences on board - #O sequences on board, when empty board 
both are 8 so h value = 0
next board = 5-3 = 2
have 3 lists in 1 list to rep a matrix, and instead of Os and Xs
have constants signifying computer and human and 0 for empty spot

have quadruplet holding 4 things: board, state, turn, #empty squares
Constants: for vic and loss want extreme values to differentiate between 
vic and loss and just very high/low h value. human is always 1 and decided computer
to be size+1. need these for later computations

Heuristic: +dif->good for x, -dif->good for O. If number possible 
sequences for both is same, will get 0 and want to distinguish btw 
0 heuristic and actual tie=0 (game over). so have counter intialized to 0.1,
so starting value of h is never 0, will always get a value of _.1

only up to 4 possibilities, because can result in sequences going out of
board and sequences being repeated (always go forward-up, right)
dc and dr will be diffs we'll focus on, and each list has 4 spots for the 
4 possible sequences, if not possible, will be 0
sum up each of paths and know if for x or o becuase comp=x is >size(3) and 
human=o is <=3 -- vic and loss from pov of computer

homework:
need to come up with heuristic and doc EVERYTHING, implementing fns
getNext developes children in tree. did in class best way to order kids to get most pruning
'''