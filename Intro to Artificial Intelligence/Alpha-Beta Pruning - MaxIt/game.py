#Assignment 2: Maxit
#Tali Cohen - 329651871
#Zahava Brown - 346287956

import random
import copy
SIZE = 8  # The number of rows and columns in board
LowerBound = -9 #of potential values for tiles
UpperBound = 15 #of potential values for tiles
CompFinalScore = 0
HumFinalScore = 0


'''
The state of the game is represented by a list of 7 items:
0. The game board - a matrix (list of lists) of ints. Empty cells = 0,
   the comp's cells = COMPUTER and the human's = HUMAN
1. Row position of current player
2. Column position of current player
3. Value of current square
4. First player of game (first player moves in rows, second moves in columns)
5. Who's turn is it: HUMAN or COMPUTER 
6. Computer's score
7. Human's score
'''


def create():
    # Returns an board ready for play with numbers from -9 - 15 and a randomly chosen start location
    board = [[random.randint(LowerBound, UpperBound) for col in range(SIZE)] for row in
             range(SIZE)]  # generating values for board
    startRow = random.randint(0, SIZE-1)  # generating starting position for first player
    startCol = random.randint(0, SIZE-1)
    board[startRow][startCol] = 'C' # marks the starting position on the board
    value = 0; #current value of the board
    WhoIsRow = ' ' #this is decided by the whoIsFirst function
    Current = ' '  #this changes each turn
    CmpScore = 0   #current scores for both players
    HumScore = 0
    game = [board, startRow, startCol, value, WhoIsRow, Current, CmpScore, HumScore]
    return game


# print the game board
def printState(board):
    # Game over
    if(isFinished(board)):    
        print("Game Over!")
        if (CompFinalScore < HumFinalScore):
            print("Well Done! You Won!")
        elif (HumFinalScore < CompFinalScore):
            print("Sorry, You Lost!")
        else:
            print("it's a TIE!")

        print("Computer Score: ", CompFinalScore)
        print("Your Score: ", HumFinalScore)
        return
    print('MAXIT Board Game\n')
    # prints top border of game 
    print('   0 ||', end='')
    for col in range(SIZE):
        print('%4d |' % (col + 1), end='')
    print('\n ------', end='')
    # handles row indicies
    for col in range(SIZE):
        print('------', end='')
    for row in range(SIZE):
        if (row >= 0):
            print('\n%4d ||' % (row + 1), end='')
    #prints actual board contents
        for col in range(SIZE):
            # form = '%' + str(max(msize)) + 's'
            print('%4s |' % str(board[0][row][col]), end='')
    print('\n')
    return


def whoIsFirst(s):
    # The user decides who plays first, s[4] will remain unchanged throughout and deignates who plays rows, s[5] is current player
    if int(input("Who plays first? 1-me / anything else-you. : ")) == 1:
        s[4] = 'COMPUTER'
        s[5] = 'COMPUTER'
    else:
        s[4] = 'HUMAN'
        s[5] = 'HUMAN'
    return


def isHumTurn(s):
    # Returns True iff it the human's turn to play
    return (s[5] == 'HUMAN')


def value(s):
    # Returns the heuristic value of s, the score of the current player
    if (isHumTurn(s)):
        return s[7]
    else:
        return s[6]


# helper function to get the possible next moves for the row player
def rowPlayer(s):
    newOptions = []
    row = s[1] #current position on board (marked by a 'C'
    col = s[2]
    tempBoard = s[0]
    for i in range(SIZE):
        copyBoard = copy.deepcopy(tempBoard)
        copyBoard[row][col] = ' ' #blanks the current position in preperation for new current position
        if ((tempBoard[row][i] != 'C') and (tempBoard[row][i] != ' ')): # if its a legal choice
            val = tempBoard[row][i] #record value of tile chosen
            copyBoard[row][i] = 'C' #replace with 'C' to mark new current position
            newOptions.append([copyBoard, row, i, val, s[4], s[5], s[6], s[7]]) #add to list of possibilities
    return newOptions


# helper function to get the possible next moves for the column player
# as the row player function
def colPlayer(s):
    newOptions = []
    row = s[1]
    col = s[2]
    tempBoard = s[0]
    for i in range(SIZE):
        copyBoard = copy.deepcopy(tempBoard)
        copyBoard[row][col] = ' '
        if ((tempBoard[i][col] != 'C') and (tempBoard[i][col] != ' ')): 
            val = tempBoard[i][col]
            copyBoard[i][col] = 'C'
            newOptions.append([copyBoard, i, col, val, s[4], s[5], s[6], s[7]])
    return newOptions


def NoLegalMoves(s):
    #return false if there are no legal moves
    if (s[4] == s[5]):  # current player moves within a row
        for i in range(SIZE):
            if (s[0][s[1]][i] != 'C' and s[0][s[1]][i] != ' '): #if there is a legal move
                return True
        return False
    else:  # current player moves within a column
        for i in range(SIZE):
            if (s[0][i][s[2]] != 'C' and s[0][i][s[2]] != ' '): #if there is a legal move
                return True
        return False


# returns a list of the next states of s
def getNext(s):
    ns = ' '
    if (s[4] == s[5]): #if s[5](currentplayer) is also the first player and therefore rowPlayer
        ns = rowPlayer(s)
    else:
        ns = colPlayer(s)

    if (ns != False):  # would be false if the function called above returned no possible moves
        for l in range(len(ns)):
            makeMove(ns[l], 0, 0, False)
        # sort according to human score if human turn
        if (isHumTurn(s)):
            ns.sort(key=lambda x: x[7], reverse=True)
        # sort according to computer score if computer turn
        else:
            ns.sort(key=lambda x: x[6], reverse=True)

    return ns


# gets heuristic values for each state that gets sent to it
#input determines who called it - computer or human
def makeMove(ns, row, col, Input):
    if (Input):
        ns[3] = ns[0][row][col]  # getting value of chosen square
        ns[0][row][col] = 'C' #marking chosen square as current position
        ns[0][ns[1]][ns[2]] = ' '  # wherever it was before is now empty
        ns[1] = row #recording new position in the game state
        ns[2] = col
   # switches turns and updates heuristic value of current player
    if (isHumTurn(ns)):
        ns[5] = 'COMPUTER'
        ns[7] += ns[3]
    else:
        ns[5] = 'HUMAN'  # switches turns and updates heuristic value
        ns[6] += ns[3]
    return


def inputMove(s):
    # Reads, enforces legality and executes the user's move.
    printState(s)
    print("Current Scores: Computer: ", s[6], " You: ", s[7])
    flag = True
    # keeps looping until flag set to false -> legal move was made
    while flag:
        RorC=''
        if(s[5]==s[4]):
            RorC='ROWS'
        else:
            RorC='COLUMNS'
        print("You are playing: ", RorC)
        row = int(input("Enter your next move - first the row: "))
        col = int(input("Now enter the column: "))
        row -= 1  # user putting in 1-8, board is 0-7
        col -= 1
        if (row < 0 or row >= SIZE or col < 0 or col >= SIZE):
            print("Illegal move.")
        # is row player
        elif (s[5] == s[4] and (row != s[1] or s[0][row][col] == ' ' or s[0][row][col] == 'C')):
            print("Illegal move.")  # user tried to move in col
        # is col player
        elif (s[5] != s[4] and (col != s[2] or s[0][row][col] == ' ' or s[0][row][col] == 'C')):
            print("Illegal move.")  # user tried to move in row
        else:
            flag = False
            makeMove(s, row, col, True)  # user gave legal move so now can make it

def isFinished(s):
    # Returns True iff the game ended
    if(not NoLegalMoves(s)):
        global CompFinalScore
        global HumFinalScore
        CompFinalScore = s[6]  # game is over so need to update final scores so can calculate winner
        HumFinalScore = s[7]
        return True
    else:
        return False
