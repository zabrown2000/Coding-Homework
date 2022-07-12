import math

'''
Computes the dot product of the vectors x and y (lists of numbers).
Assumes that x and y have the same length.
'''
def dot_prod(x ,y):
    return sum([x[i]*y[i] for i in range(len(x))])

def sigmoid(t, x): #1 / 1 + e^-(theta * x)
    return 1 / (1 + math.exp(-dot_prod(t ,x)))

def gradient_descent(function, derivative, epsilon, alpha, x): #the x is actually theta t
    f = function(x)
    prevf = f + 1 + epsilon
    while abs(prevf-f) > epsilon: #epsilon sent to function
        x = [x[i] - alpha*derivative(i,x) for i in range(len(x))] #go down against gradient for each theta
        prevf = f
        f = function(x)        
    return x #when finish return. take value before and and after change and add epsilon
'''
short code, but very general. Can use it to find min of any function, here it be logistic function
'''

def function(t): #logistic function
    global ds
    return -sum([ds[i][-1]*math.log(sigmoid(t,[1] + ds[i][:-1])) + \
                 (1-ds[i][-1])*math.log(1-sigmoid(t,[1] + ds[i][:-1]))\
                      for i in range(len(ds))]) / len(ds)

def derivative(j ,t): #partial derivative for every theta
    global ds
    return sum([((sigmoid(t,[1] + ds[i][:-1])) - ds[i][-1]) * ([1] + ds[i])[j] \
            for i in range(len(ds))]) / len(ds)

def classify(t, x):
    return round(sigmoid(t, [1]+x)) #have 1+ for extra dim of thetas

#The function should read the file specified in its input argument,
# and should return a list containing the dataset in the file.
def reads(filename):
    return

#The function should save model t to file filename. The model should be saved to the file
#as a sequence of values separated by spaces
def save_model(fiename, t):
    return

ds = [[1,1,0],[2,3,1],[3,2,1]] #list of lists, 3 examples, 2 attributes with label 0/1
#in hw, type data up in file to give to algo, like 3 lines of 3 #s, or can do more elaborate data sets or find datasets online
#hw will be to separate code from data
t = [1,1,1] #t is our thetas, since dimension 2 for attributes, theta is dim 3 with default random values for them to start with
t = gradient_descent(function, derivative, 0.000001, 0.001, t)
#need to formulize deri of fn - she'll solve for us or we can look up or take from slides)
#sending name of funcitons to know which derivative using and what it is we'll minimize, the values for gradient desc, and curretn t
#returns optimal t (theta)
print (t)
print("+++++++++++++++++")
print (classify(t , [1,1])) #apply classify with t we got on each set and want t to be s.t. when use them to classify matches label given above
print (classify(t , [2,3]))
print (classify(t , [3,2]))
