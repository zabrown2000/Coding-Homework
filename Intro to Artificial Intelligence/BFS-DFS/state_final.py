'''
Assignment 1: n-squares
Tali Cohen - 329651871
Zahava Brown - 346287956
2. This heuristic is admissable. In class we discussed that the Manhattan distance heuristic is admissable, and the count of displaced numbers is admissable and since
   this heuristic is less optimistic than the count of displaced tiles and more optimistic than the Manhattan distance (as it takes the max of the 2 displacements rather than the sum),
   then this heuristic is admissable as well.

3. There is an improvement in this heuristic over the one done in class (count of displaced tiles). The amount of states in the frontier at any one 
   time with the min displaced tiles heuristic is 40175, while this one is 6473, and the amount of memory needed is 16920 and 2608 respectively.
   The improvement is due to the values being returned by the hdistance function. Val calls hdistance which is then used in 
   insert and heapify. So, less states are being moved into the frontier at a time resulting in less memory needed to keep
   track of all the states.
'''

'''
The state is a list of 2 items: the board, the path
The target for 8-puzzle is: (zero is the hole)
012
345
678
'''

import random
import math


# returns a random board nXn
# change so start with fixed state every time, so can compare results
def create(n):
    s = list(range(n * n))  # s is the board itself. a vector that represent a matrix. s=[0,1,2....n^2-1]
    s = [4, 3, 7, 5, 8, 6, 1, 0, 2]  # hardcoded an initial state, this is difficult state, took a long time
    # 1326092 - how many states in frontier at any one time
    # 581287 amount of memory needed, max amount states in frontier
    #with min tiles heuristic: 40175, 16920
    # m="<>v^"                # m is "<>v^" - for every possible move (left, right, down, up)
    # for i in range(n**3):  # makes n^3 random moves to mix the tiles
    # if_legal(s,m[random.randrange(4)])
    return [s, ""]  # at the beginning "" is an empty path, later on path
    # contains the path that leads from the initial state to the state


def get_next(x):  # returns a list of the children states of x
    ns = []  # the next state list
    for i in "<>v^":
        s = x[0][:]  # [:] - copies the board in x[0]
        if_legal(s, i)  # try to move in direction i
        # checks if the move was legal and...
        if s.index(0) != x[0].index(0) and \
                (x[1] == "" or x[1][-1] != "><^v"[
                    "<>v^".index(i)]):  # check if it's the first move or it's a reverse move
            ns.append([s, x[1] + i])  # appends the new state to ns
    return ns


def path_len(x):
    return len(x[1])  # at x[1] stored is sequence of steps, g function


def is_target(x):
    n = len(x[0])  # the size of the board
    return x[0] == list(range(n))  # list(range(n)) is the target state


#############################
def if_legal(x, m):  # gets a board and a move and makes the move if it's legal
    n = int(math.sqrt(len(x)))  # the size of the board is nXn
    z = x.index(0)  # z is the place of the empty tile (0)
    if z % n > 0 and m == "<":  # checks if the empty tile is not in the first col and the move is to the left
        x[z] = x[z - 1]  # swap x[z] and x[z-1]...
        x[z - 1] = 0  # ...and move the empty tile to the left
    elif z % n < n - 1 and m == ">":  # check if the empty tile is not in the n's col and the move is to the right
        x[z] = x[z + 1]
        x[z + 1] = 0
    elif z >= n and m == "^":  # check if the empty tile is not in the first row and the move is up
        x[z] = x[z - n]
        x[z - n] = 0
    elif z < n * n - n and m == "v":  # check if the empty tile is not in the n's row and the move is down
        x[z] = x[z + n]
        x[z + n] = 0

def verticleDisplacement(s, i):
    n = int(math.sqrt(len(s[0]))) #getting the dimension of the board
    return abs((i // n) - s[0].index(i)//n) #returning the displacement of the rows, where it should be - where element is

def horizontalDisplacement(s, i): #getting the dimension of the board
    n = int(math.sqrt(len(s[0])))
    x = i % n
    y = s[0].index(i) % n
    return abs((i % n) - s[0].index(i)%n) #returning the displacement of the columns, where it should be - where element is


# This is your HW
def hdistance(s):  # the heuristic value of s - # misplacedtiles or manhattan distance (better)
    error = 0
    for i in range(1, len(s[0])):
        error += max(verticleDisplacement(s, i), horizontalDisplacement(s, i)) #calling displacements for each element and choosing the max of the 2
    return error

