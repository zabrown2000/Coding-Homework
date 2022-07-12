import random #will be doing reandom local greedy search

#with nqueens no care about path to get to goal state
#amount of possible states: n^2! / ((n^2-n)! * n!) n!->way to arrange queens amongst themselves
#there are (n-1)n neighboring states. Choose 1 of n states, and each state has n-1 neighbors


'''
for col: move forward, go through each element, if any of ones after it are same, add to counter
for diag: if horiz and vert distances are the same between 2 queens, then on same diag
'''
def threats(board):
    #heuristic - returns number of threats in board (the value of a state)
    count=0
    for i in range(0, len(board)-1):
        for j in range(i+1, len(board)):
            if board[i]==board[j] or abs(i-j)==abs(board[i]-board[j]): #col or diagonal
                count=count+1
    return count

def rndboard(x): #x is the n
    #returns a board x*x with queens in random cols
    #the way making board, no way for 2 queens to be in same row, already reducing state options, to n^n (smaller than above)
    board=[]
    for i in range(x):
        board.append(random.randrange(x))
    return board

def printboard(board):
    #prints the board: #= empty cell Q=a queen
    print()
    for r in range(len(board)):
        for c in range(len(board)):
            if board[r]==c:
                print('Q', end='')
            else:
                print('#', end='')
        print()
    return

def improve(board):
    #improves board if improvment is possible,
    minimum=threats(board) #returns num of threats in the board
    improved=[0,board[0]]#improved holds the best move
    stateEqual = []
    for r in range(len(board)):
        tmp=board[r]
        for c in range(len(board)):
            board[r]=c
            x=threats(board)
            if x<minimum:
                minimum=x
                improved=[r,c]
            elif x==minimum:
                stateEqual.append(x)
    if (minimum == board) and (stateEqual.len() != 0):
        minimum = random.range(stateEqual)
        board[r]= tmp
    board[improved[0]]=improved[1]
    return minimum


def solve(size):
    ctrStates = 0
    ctrRestart = 0
    #solves the (size) quenns problem
    b=rndboard(size) #returns random board state
    n=threats(b) #want value for this state, the num of threats
    while n>0: #can go into inifinte loop if not solvable, never reaches 0
        x=improve(b) #next potential state
        ctrStates += 1
        if x==n: #if stays same, local min, so restart
            b=rndboard(size)
            ctrRestart += 1
            #print("restarting")
            n=threats(b)
        else:
            n=x #lowering it
    #printboard(b)
    #print("States: " + str(ctrStates))
    #print("Restarts: " + str(ctrRestart))

totalStates = 0
totalRestarts = 0
for i in range(100):
    (states, restarts) = solve(10)
    totalStates += states
    totalRestarts += restarts

avgStates = totalStates / 100
avgRestarts = totalRestarts / 100

print("Average States: " + str(avgStates))
print("Average Restarts: " + str(avgRestarts))
'''
for 1000 loops
Average States: 76.33
Average Restarts: 14.339
'''
