from collections import defaultdict, deque


def dfs(visited,adj,src):
    visited.append(src)
    print(src)
    
    for node in adj[src]:
        if node not in visited:
            dfs(visited,adj,node)



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

dfs([],adj,src)
    


'''
5
1
2
3
4
5
'''    



    
