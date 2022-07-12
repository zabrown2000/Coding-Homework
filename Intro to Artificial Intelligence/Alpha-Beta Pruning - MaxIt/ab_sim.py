#from week6
#generic game for pruning

import random
import math

count=0 #Counter of the num. of developed nodes.

'''
Simulates the maximum players alpha-beta pruning algorithm
bf=the branching factor
d=the trees depth
a=alpha
b=beta
'''
#with depth = 16, even so max is one to reach d=0

def abmax(bf,d,a,b):
    global count
    count+=1
    if d==0:
        #return count #hardcoding to be inc left to right leaves, doing in min won't do anything got:2621441, 11.453445572976449
        #return -count  # hardcoding to be dec left to right leaves, doing in min won't do anything got: 1114112, 10.836212670985748
        #return random.randrange(1, 1000000000)
        return 0 #values for all leaf=0, 283970, 9.850170749737364 - condition always holds, max number of pruning with less nodes
    v=float("-inf")
    for i in range(bf):
        tmp=abmin(bf,d-1,a,b)
        if tmp>=b:
            return tmp
        if tmp>a:
            a=tmp
        if tmp>v:
            v=tmp
    return v
            
def abmin(bf,d,a,b): #missing code here
    global count
    count += 1
    if d == 0:
        #return count #hardcoding to be inc left to right leaves - no changes will affect, if d odd number would change heres
        return random.randrange(1, 1000000000) #can change lower bound to be previously generated numberm, so always inc
    v = float("inf")
    for i in range(bf):
        tmp = abmax(bf, d - 1, a, b)
        if tmp <= a:
            return tmp
        if tmp < b:
            b = tmp
        if tmp < v:
            v = tmp
    return v
'''
Your code comes here.
Implement the minimum player in alpha-beta pruning
'''

#want to simulate how many nodes being developed
def simulate(b,d):
    abmax(b,d,float("-inf"),float("inf"))
    #since simulating, always assume branching factor of b, in real game it's developed. Here send it as param

def calc_effective_d(b):
    #count = b^d+1 – 1)/(b-1)
    innerLog = (count * b) - count + 1
    #innerLog = innerLog / b
    height = math.log(innerLog - 1, b)
    return height #ends up being smaller than d defined bellow, deeper can go, better for player, want to go deeper in same amoutn of time


'''
Your code comes here.
calculate the effective height of the developed tree
from b (the branching factor) and count(the number of nodes developed).
'''
        
d=16 #Depth of the tree
b=4  #Branching factor
simulate(b,d) #with d16 and b4 get around 30,196,573 nodes (next time got 34,154,544)
# without pruning, its 5,726,623,061 (see equation to get in word doc)
print(count)
print(calc_effective_d(b))
