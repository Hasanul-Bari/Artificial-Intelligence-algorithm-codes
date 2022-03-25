from collections import defaultdict, deque
from queue import PriorityQueue

def printpath(parent,src,goal):
    print(parent)
    l=[goal]
    while src!=goal:
        goal=parent[goal]
        l.append(goal)
    l.reverse()
    print("Path :",l)

def best_first(adj,heuristics,src,goal):
    
    pq=PriorityQueue()
    
    visited=[src]
    pq.put((heuristics[src],src))
    parent={src:-1}
    
    while pq:
        x=pq.get()[1]
        print(x)
        
        for node in adj[x]:
            if node not in visited:
                parent[node]=x
                visited.append(node)
                if node==goal:
                    print("Solution found")
                    printpath(parent, src, goal)
                    return 
                else:
                    pq.put((heuristics[node],node))
    
    
    
    print("Solution not found")


n=int(input("Enter the number of nodes : "))

nodes=[]
heuristics=dict()

print("Enter",n,"nodes")
for i in range(n):
    x=input("node"+str(i+1)+" : ")
    h=input("heuristics value of node "+str(i+1)+" : ")
    nodes.append(x)
    heuristics[x]=h
    
    
print(heuristics)
    
e=int(input("Enter the number of edges : "))

adj=defaultdict(list)

for i in range(e):
    print("Edge",i+1," : ")
    v=input("Start Node : ")
    u=input("End Node : ")
    
    if u not in nodes or v not in nodes:
        print("Invalid Edge")
        quit()
    
    adj[v].append(u)
    adj[u].append(v)
    
#print(adj)
src=input("Enter the source node : ")
goal=input("Enter the goal node : ")


best_first(adj,heuristics,src,goal)
    


'''
8
A
40
B
32
C
25
D
35
E
14
F
17
G
0
H 
10
10
A
B
A
C
A
D
B
E
C
E
C
F
D
F
E
H
F
G
H
G
'''    



    
