import CSProblem
import copy

def solve(n):
    p=backtrack(CSProblem.create())
    CSProblem.present(p)

def backtrack(p):
    var=next_var(p) #MRV, p is board with domain
    if var==None:
        return p
    dom=sorted_domain(p, var, LCV=True) #LCV
    for i in dom:
        bu=copy.deepcopy(p)
        CSProblem.assign_val(bu, var, i)
        propagate_constraints(bu, var) #prop constraints, last heuristic
        bu=backtrack(bu) #recursive, doing dfs as go down
        if CSProblem.is_solved(bu):
            return bu
    return p

def sorted_domain(p, var, LCV=True):
    if LCV==False:
        return CSProblem.domain(p,var)
    l=[]
    for i in CSProblem.domain(p,var):
        l+=[[p,var,i]]
    sd=[]
    for i in sorted(l, key=num_of_del_vals):
        sd+=[i[2]]
    return sd

def num_of_del_vals(l):
#l=[problem, the variable, the val. assigned to the var.]
#returns the num. of vals. erased from vars domains after assigning x to v
    count=0
    for inf_v in CSProblem.list_of_influenced_vars(l[0], l[1]):
        for i in CSProblem.domain(l[0], inf_v):
            if not CSProblem.is_consistent(l[0], l[1], inf_v, l[2], i):
                count+=1
    return count
        
def next_var(p, MRV=True):
#Returns next var. to assign
#If MRV=True uses MRV heuristics
#If MRV=False returns first non-assigned ver.
    if MRV==False:
        v=CSProblem.get_list_of_free_vars(p)
        if v==[]:
            return None
        else:
            return v[0]
    m=float("inf")
    mrv=None
    for i in CSProblem.get_list_of_free_vars(p):
        ds=CSProblem.domain_size(p, i)
        if ds<m:
            m=ds
            mrv=i
    return mrv
           
def propagate_constraints(p, v):
    for i in CSProblem.list_of_influenced_vars(p, v):
        for x in CSProblem.domain(p, i):
            if not CSProblem.is_consistent(p, i, v, x, CSProblem.get_val(p, v)):
                CSProblem.erase_from_domain(p, i, x)
        
    
    
solve(3)

        
