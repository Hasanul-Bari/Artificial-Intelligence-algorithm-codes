from collections import defaultdict, deque
import heapdict


def printpath(parent,src,goal):
    print(parent)
    l=[goal]
    while src!=goal:
        goal=parent[goal]
        l.append(goal)
    l.reverse()
    print("Path :",l)

def a_star_search(adj,heuristics,src,goal):
    
    open=heapdict.heapdict()
    close=[]
        
    dist={src:0}
    open[src]=heuristics[src]+dist[src]
    parent={src:-1}
    
    while open:
        curr_node,curr_f=open.popitem()
        
        print(curr_node, dist[curr_node],curr_f)
        
        if curr_node==goal:
            print("Solution found")
            printpath(parent, src, goal)
            return 
        
        close.append(curr_node)
        
        for node in adj[curr_node]:
    
            if node[0] not in close:
                
                if node[0] in list(open.keys()):
                    if dist[node[0]]>dist[curr_node]+node[1]:
                        dist[node[0]]=dist[curr_node]+node[1]
                        open[node[0]]=heuristics[node[0]]+dist[node[0]]
                        parent[node[0]]=curr_node
                else:
                    dist[node[0]]=dist[curr_node]+node[1]
                    open[node[0]]=heuristics[node[0]]+dist[node[0]]
                    parent[node[0]]=curr_node
                        
    print("Solution not found")


n=int(input("Enter the number of nodes : "))

nodes=[]
heuristics=dict()

print("Enter",n,"nodes")
for i in range(n):
    x=input("node"+str(i+1)+" : ")
    h=int(input("heuristics value of node "+str(i+1)+" : "))
    nodes.append(x)
    heuristics[x]=h
    
    
print(heuristics)
    
e=int(input("Enter the number of edges : "))

adj=defaultdict(list)

for i in range(e):
    print("Edge",i+1," : ")
    v=input("Start Node : ")
    u=input("End Node : ")
    c=int(input("Enter Cost : "))
    
    if u not in nodes or v not in nodes:
        print("Invalid Edge")
        quit()
    
    adj[v].append((u,c))
    adj[u].append((v,c))
    
#print(adj)
src=input("Enter the source node : ")
goal=input("Enter the goal node : ")


a_star_search(adj,heuristics,src,goal)
    


'''
7
0
14
1
12
2
11
3
6
4
4
5
11
6
0
9
0
1
4
0
2
3
2
3
7
2
4
10
3
4
2
1
4
12
1
5
5
4
6
5
5
6
16

'''    



    
