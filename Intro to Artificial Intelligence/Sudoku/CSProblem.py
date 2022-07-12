#Zahava Brown - 346287956
#Tali Cohen - 329651871

#SUDOKU
import math
#import CSPSolver
#board - The variables' value are in a list of the (N*N)*(N*N) board cells
#            (a vector represenring a mat.).
#an empty cell contains 0.
#
#d - The domains are a list of lists - the domain of every var.
#
#The state is a list of 2 lists: the vars. and the domains.

N=0
def create(fpath="sudoku.txt"):
    global N
    board=read_board_from_file(fpath)
    N=int(len(board)**0.25)
    #p has 2 elements - board, 81 sublists with constraints
    p = [board, [''] * N**4]

    #now need to loop through each num in board, and if has num constraint array is th at num
    #if its 0, find what it can't be using
    for i in range(N**4): #list of all tiles on board
        if p[0][i] != 0: #if already assigned, no options
            p[1][i] = " "
        else:
            p[1][i] = [1,2,3,4,5,6,7,8,9] #default - start with all options available
            iRow = i // N**2
            iCol = i % N**2
            start=iRow*(N**2) #beginning point for checking row contraints 
            lim = start+(N**2) #end point for checking row constraints
            removed = [1] * 9 #keeping track if something deleted to bypass python remove exception
            #loop over all in same row, col, subset and check val of every tile against potential already assigned
            #checking values in row
            for k in range(start, lim):
                if p[0][k] != 0:
                    toErase = get_val(p, k)
                    erase_from_domain(p, i, toErase) #as contraints found remove bad options
                    removed[toErase - 1] = 0 #update record of removed values so as not to try and remove twice
             #if value not deleted yet, check if in column
            for k in range(iCol, (iCol+((N ** 2)*(N**2)-1)), 9):
                if p[0][k] != 0:
                    toErase = get_val(p, k)
                    if removed[toErase -1] != 0:
                      erase_from_domain(p, i, toErase)
                      removed[toErase - 1] = 0
                # if value not deleted yet, check if in subset/box
            for k in get_subset(i):
                if p[0][k] != 0:
                   toErase = get_val(p, k)
                   if removed[toErase - 1] != 0:
                     erase_from_domain(p, i, toErase)
                     removed[toErase - 1] = 0
    return p  #p is initial state, the initial board with contraints

def read_board_from_file(fpath):
    f=open(fpath, "r")
    board=[]
    s=f.readline()
    while s!="":
        for i in s.split():
            board+=[int(i)]
        s=f.readline()
    f.close()
    return board

def domain(problem, v):
#Returns the domain of v
    return problem[1][v][:]

def domain_size(problem, v):
#Returns the domain size of v
    return len(problem[1][v])

def assign_val(problem, v, x):
#Assigns x in var. v
    problem[0][v]=x

def get_val(problem, v):
#Returns the val. of v
    return problem[0][v]
    
def erase_from_domain(problem, v, x):
#Erases x from the domain of v
    problem[1][v].remove(x)

def get_list_of_free_vars(problem):
#Returns a list of vars. that were not assigned a val.
    l=[]
    for i in range(len(problem[0])):
        if problem[0][i]==0:
            l+=[i]
    return l

def is_solved(problem):
#Returns True iff the problem is solved
    for i in range(len(problem[0])):
        if problem[0][i]==0:
            return False
    return True
    
def is_consistent(problem, v1, v2, x1, x2): #problem is the statepair
#Returns True iff v1=x1 and v2=x2 is consistent with all constraints (sudoku rules)

     #getting information on locations of v1 and v2
    v1Row = v1 // N**2
    v2Row = v2 // N**2
    v1Col = v1 % N**2
    v2Col = v2 % N**2
    v1Subset = get_start_of_subset(v1)
    v2Subset = get_start_of_subset(v2)

    #if v1 and v2 are in the same row, column, or box(subset), then there is a possibility of constraints conflict
    if (v1Row == v2Row) or (v1Col == v2Col) or (v1Subset == v2Subset):
        if x1 == x2:
            return False
    return True #no constraints violated




def list_of_influenced_vars(problem, v):
#Returns a list of free vars. whose domain will be
#influenced by assigning a val. to v
    r=list(range(N**4))
    r.remove(v)
    l=[]
    for i in r:
        if problem[0][i]==0 and not is_consistent(problem,v,i,1,1): #in this context when send same value for x1 and x2 get result we want
            l+=[i]
    return l

def present(problem):
    for i in range(len(problem[0])):
        if i%(N*N)==0:
            print()
        x=str(problem[0][i])
        pad=( math.ceil(math.log(N*N, 10)) - len(x) )
        print(pad*" ", x, end="")
    print()   

#function to get all box indices for a given index
def get_subset(index):
    sets = [ [0, 1, 2,9, 10, 11,18, 19, 20],
              [3, 4, 5,12, 13, 14,21, 22, 23],
              [6, 7, 8,15, 16, 17, 24, 25, 26],
              [27, 28, 29, 36, 37, 38, 45, 46, 47],
              [30, 31, 32, 39, 40, 41, 48, 49, 50],
              [33, 34, 35, 42, 43, 44, 51, 52, 53],
              [54, 55, 56, 63, 64, 65, 72, 73, 74],
              [57, 58, 59, 66, 67, 68, 75, 76, 77],
              [60, 61, 62, 69, 70, 71, 78, 79, 80] ]
    for i in range(81):
        if index in sets[i]:
            return sets[i]

#function to get top-left number of each subsquare
def get_start_of_subset(index):
    subset = get_subset(index)
    return subset[0]



