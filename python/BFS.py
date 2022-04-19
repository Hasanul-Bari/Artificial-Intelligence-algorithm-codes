from collections import defaultdict, deque

def printpath(parent,src,goal):
    l=[goal]
    while src!=goal:
        goal=parent[goal]
        l.append(goal)
    l.reverse()
    print("Path :",l)

def bfs(adj,src,goal):
    
    if src==goal:
        print("path : ",[src])
        return
    
    visited=[src]
    queue=deque([src])
    parent={src:-1}
    
    while len(queue):
        x=queue.popleft()
        #print(x)
        
        for node in adj[x]:
            if node not in visited:
                parent[node]=x
                visited.append(node)
                if node==goal:
                    print("Solution found")
                    printpath(parent, src, goal)
                    return 
                else:
                    queue.append(node)
                        
                    
    print("Solution not found")
    



n=int(input("Enter the number of nodes : "))

nodes=[]

print("Enter",n,"nodes")
for i in range(n):
    x=input("node"+str(i+1)+" : ")
    nodes.append(x)
    
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

bfs(adj,src,goal)
    


'''
8
1
2
3
4
5
6
7
8
8
1
2
1
3
1
4
2
5
2
6
3
7
3
8
4
8
'''    



    
