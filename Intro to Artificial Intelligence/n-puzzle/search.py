# search
import state
import frontier


def search(n):
    s = state.create(n)
    print(s)
    f = frontier.create(s)
    while not frontier.is_empty(f):
        s = frontier.remove(f)
        if state.is_target(s):
            return [s, f[1], f[3]]  # not just returning s, doing h[1] and h[3] (f[0] is frontier)
        ns = state.get_next(s)
        for i in ns:
            frontier.insert(f, i)
    return 0


print(search(3))
