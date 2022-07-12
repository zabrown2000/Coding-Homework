import state


# implements a priority queue -> informed search
# [list of states, total num of states, curr. num. of states, max. num. of states]
# with bfs, used queue DS, uninformed search, now doing informed search
# needed to check inner workings of each function to work as priority queue (heap) and not reg queue
def create(s):
    return [[s], 0, 0, 0]


def is_empty(f):
    return f[0] == []


def val(s):
    return state.hdistance(s) + state.path_len(s)  # hdistance is h and pathlen is g -> A* = h + g


# Uniform Cost: return state.path_len(s)
# Greedy Best First: return state.hdistance(s)

def insert(h, s):  # h is our quadruple
    # inserts state s to the frontier
    f = h[0]  # the heap
    h[1] += 1  # anytime reach new state
    h[2] += 1  # auxiliary used for h[3]
    if h[2] > h[3]:
        h[3] = h[2]
    f.append(s)  # adding to heap. start at bottom and roll way up if smaller than parent
    i = len(f) - 1
    while i > 0 and val(f[i]) < val(f[(i - 1) // 2]):  # parent is at [i/2]
        t = f[i]
        f[i] = f[(i - 1) // 2]
        f[(i - 1) // 2] = t
        i = (i - 1) // 2


def remove(h):
    if is_empty(h):
        return 0
    h[2] -= 1
    f = h[0]
    s = f[0]
    f[0] = f[len(f) - 1] #put root in last place and then heapify
    del f[-1]
    heapify(f, 0)
    return s


def heapify(f, i): #can check code from last year to review
    minSon = i
    if 2 * i + 1 < len(f) and val(f[2 * i + 1]) < val(f[minSon]):
        minSon = 2 * i + 1
    if 2 * i + 2 < len(f) and val(f[2 * i + 2]) < val(f[minSon]):
        minSon = 2 * i + 2
    if minSon != i:
        t = f[minSon]
        f[minSon] = f[i]
        f[i] = t
        heapify(f, minSon)
