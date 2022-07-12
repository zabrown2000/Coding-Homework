import random
import matplotlib.pyplot as plt

width = 100
height = 100
gap = 50
size = 50 #50*49 / 2 = 1225 dif experiments to run, run it on everyposible pair of centers, some of choices converge to same cluster

def distance(x, y):  #euclidean distance
    return sum( (x[i]-y[i])**2 for i in range(len(x)))

def create_dataset(): #has a structure but it's still random
    ds = []
    for i in range(size):
        #makes clusters top and bottom
        #ds += [[random.randrange(0,width) , random.randrange(0,(height-gap)//2)]] #lower cluster
        #ds += [[random.randrange(0,width) , random.randrange(((height+gap)//2),height)]] #upper cluster
        #right and left
        ds += [[random.randrange(0, (width - gap) // 2), random.randrange(0, height)]]
        ds += [[random.randrange(((width + gap) // 2), width), random.randrange(0, height)]]
        #can add more lines to get more clusters and need to add more centers so see 4 colros
    return ds

def point2int(p):
    return p[1] * width + p[0]

def nearest(point, centers): #loop over all centers and calc distamce from point to each center and one with smallest distamce belongs to that center
    m = 0
    for i in range(1, len(centers)):
        if distance(point, centers[i]) < distance(point, centers[m]):
            m = i
    return m

def find_centers(clusters):
    centers = [] #points are static and centers dynmaic
    for cluster in clusters:
        center = [0] * len(cluster[0])
        for point in cluster:
            for i in range(len(point)):
                center[i] += point[i]/len(cluster)
        centers += [center]
    return centers

def kmeans(ds, centers):
    while True: #can ad counter to see how many iterations have before converges and then in experiment get average of how many times run in kmeans
        clusters =[]
        for i in range(len(centers)): #initialize empty clusters
            clusters += [[]]
        for i in range(len(ds)):#assign each point to a cluster
            clusters[nearest(ds[i], centers)] += [ds[i]]
        #can put show here and then call kmeans from bottom to just run it once
        new_centers = find_centers(clusters) #recalc cluster centers
        if new_centers == centers:
            return [centers, clusters] #current pair of the centers and the clusters corresponding to each one
        centers = new_centers

def experiment(plot = False):
    ds = create_dataset()
    centers = []
    for i in range(len(ds)-1): #loop over all points ecxcept last
        for j in range(i+1, len(ds)): #goes over current point to the end
            if ds[j] != ds[i]: #want to make sure not generating same data point more than once
                seeds = [ds[i][:],ds[j][:]] #pair of points, at i and j, x is vector of initial coords
                #when seeds are on top and bottom, clustering is top and bottom, but if both on top/bottom, clustering comes
                #out dif, and split to right and left and not top and bottom
                c = kmeans(ds, seeds) #run kmeans, gets datset and initial centers, want to see how results affect kmeans algo, an experiment
                sorted_c = sorted(c[0], key = point2int) #sorting the centers, 2d points, so make them ints so can sort
                                      #sort so merge results of possible points, cuz many convergre to same result, otherwise have 1225 charts
                if sorted_c not in centers:
                    if plot:
                        show(c, seeds)
                    centers += [sorted_c]
    return len(centers) #ouputs the amount of times did a recenter (plots new for each pair of centers), some pairs are clustered together

def show(c, initalCenters):
    for p in c[1][0]:
        plt.plot(p[0], p[1], "bs")
    for p in c[1][1]:
        plt.plot(p[0], p[1], "rs")
    plt.plot(c[0][0][0], c[0][0][1], "b^")#triangles are centers of final clusters
    plt.plot(c[0][1][0], c[0][1][1], "r^")
    #plotting intial centers before ran kmeans on points
    plt.plot(initalCenters[1][0], initalCenters[1][1], "go")
    plt.plot(initalCenters[0][0], initalCenters[0][1], "yo")
    plt.show()

c = 0
for i in range(1):
    c += experiment(plot=True)
print(c)



