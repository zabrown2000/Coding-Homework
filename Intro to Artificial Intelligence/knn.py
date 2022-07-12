import heap
import math
import random
import matplotlib.pyplot as plt

#will see how to plot graphs
#code creates random data with points and stuff, create the points.txt file,
#in normal situation won't need this function, will have data

#k is number of categories and look at k-closest neighbors
#it's a lazy model, no model built beforehand, doesn't do any learning
def make_points(points, n, d, c):
#craetes a file (points) with n points in a d-dimensional space, in c clusters
    f=open(points, "w")
    for i in range(n):
        s=""
        x=random.randrange(0,c) #random.randrange creates a random number 0..c-1
        for j in range(d):
        # creates numbers around x*100
            s=s+str(100*x+random.randrange(-10,10))+" "
        f.write(s+str(x)+"\n")
    f.close()

def distance(x,y,method="E"): #defalt is euc distance
    if method=="E":#Euclidean distance
        dis=0
        for i in range(len(x)):
            dis+=(x[i]-y[i])**2
        return math.sqrt(dis)
    if method=="M":#Manhattan distance
        dis=0
        for i in range(len(x)):
            dis+=abs(x[i]-y[i])
        return dis

def majority(h):
    a=[]
    while not heap.is_empty(h):
        a+=[heap.remove(h)[1]]
    a.sort()
    count=0
    maj=a[0]
    max=1
    for i in range(1,len(a)):
        if a[i]==a[i-1]:
            count+=1
            if count>max:
                max=count
                maj=a[i]
        else:
            count=1
    return maj

def knn(k, points, x): #a bit confusing, k means #of neighbors and # of categories
    h=heap.create()
    f=open(points, "r")
    s=f.readline()
    while s!="": #do for all elements in file
        s=s.split() #fn in pyhton cuts uo acc to spaces
        for i in range(len(s)):
            s[i]=int(s[i]) #makes evrything intgers
        d=distance(s[:-1],x) #looking at everthing up to label (index -1)
        heap.insert(h,[d,s[-1]])
        if heap.size(h)>k:
            heap.remove(h)
        s=f.readline()
    f.close() #at end have heap with all data
    return majority(h)


def plotPoints(points):  # points is file name
    plt.style.use('seaborn-whitegrid')
    #plt.plot(10, 10, 'o', color='red')
    #plt.plot(15, 5, 'x', color='blue')
    #plt.plot(5, 15, '+', color='black')
    f = open(points, "r")
    s = f.readline()
    while s != "":
        a = [''] * (len(s)-1)
        for i in range(len(s) - 1):
            a[i] = s[i]
        plt.plot(a, 'x', color='black')
        s = f.readline()
    f.close()

#only actually run here
num_points = 200000
dim = 2
classes = 3
make_points("points.txt", num_points, dim, classes) #200,000 points, 4 dimensions in data pints ( 4attributes and 5th is class label), 3 classes
newPoint = [50,50] #need pojnt to be 2 dims
if dim == 2:
    plotPoints("points.txt")
    plt.plot(newPoint, 'o', color='red')
    plt.show()

print(knn(3,"points.txt",newPoint)) #3=nearest neighbors, file created, point want to classify
    


            
        
        
