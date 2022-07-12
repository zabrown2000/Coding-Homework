'''
8 puzzle->3x3 15 puzzle->4x4
'''

#implements a queue
#[head, tail] - the first and last items on a linked list
#inserts to the tail and removes from the head
#every item is [value, next_item]

def create(s):
    p=[s,None]
    return [p, p]

def is_empty(f):
    return f[0] == None

def insert(f, s): #always inserting to end
    #inserts state s to the frontier
    p = [s, None] #New item
    if is_empty(f):
        f[0] = p #The head points to the new item
        f[1] = p #The tail points to the new item
    else:
        f[1][1] = p #Connects the last item to the new item
        f[1] = p    #The tail points to the new item

def remove(f): #if bfs like queue so extract from beg, FIFO, if dfs like stack so remove from in, LIFO
    if is_empty(f):
        return 0
    p = f[0][0] #value of the item at the head of the queue
    f[0] = f[0][1] #Moves the head to the next item
    if f[0] == None: #If the head is None
        f[1] = None  #the tail should also be None
    return p

'''
to make code act like dfs, make changes
can make counter to how many states dfs used vs bfs
'''