#search
import state
import frontier

def search(n):
    s=state.create(n) #calls state's create
    print(s)
    f=frontier.create(s)
    while not frontier.is_empty(f): #general search, frontier determines if will be dfs, bfs, or A*
        s=frontier.remove(f)
        if state.is_target(s):
            return s
        ns=state.get_next(s) #can make changes here too
        for i in ns:
            frontier.insert(f,i)
    return 0

print (search(3)) #with n=10, 10x10 board which takes a long time (A* algo would make it faster)
#returns 2 lists, initial board (flattened out) and then board in order with steps path


