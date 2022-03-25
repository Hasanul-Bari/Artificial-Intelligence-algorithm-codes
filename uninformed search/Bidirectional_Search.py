from collections import defaultdict, deque


def printpath(intersection,forward_parent,backward_parent,src,goal):
    print("in intersection",intersection)
    
    curr=intersection
    l1=[]
    
    while curr!=src:
        curr=forward_parent[curr]
        l1.append(curr)
    l1.reverse()
    #print(l1)
    
    curr=intersection
    l2=[]
    while curr!=goal:
        curr=backward_parent[curr]
        l2.append(curr)
    #print(l2)
    
    path=l1+[intersection]+l2
    
    print("path : ",path)


def bidirectional(adj,src,goal):
    
    if src==goal:
        print("path : ",[src])
        return
    
    visited_forward=[src]
    visited_backward=[goal]
    
    forward_queue=deque([src])
    backward_queue=deque([goal])
    
    forward_parent={src:-1}
    backward_parent={goal:-1}
    
    
    while len(forward_queue) and len(backward_queue):
    
        #forward BFS
        x=forward_queue.popleft()
        print("forward :",x)
        
    
        for node in adj[x]:
            if node not in visited_forward:
                visited_forward.append(node)
                forward_parent[node]=x
                
                if node in visited_backward:
                    printpath(node,forward_parent,backward_parent,src,goal)
                    return
                    
                forward_queue.append(node)
               
                
        #backward BFS
        x=backward_queue.popleft()
        print("backward :",x)
        
    
        for node in adj[x]:
            if node not in visited_backward:
                visited_backward.append(node)
                backward_parent[node]=x
                
                if node in visited_forward:
                    printpath(node,forward_parent,backward_parent,src,goal)
                    return
                    
                backward_queue.append(node)
                
            
    print("Path does not exist")
    
    



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

bidirectional(adj,src,goal)
    

 

'''
15
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
14
0
4
1
4
2
5
3
5
4
6
5
6
6
7
7
8
8
9
8
10
9
11
9
12
10
13
10
14
'''


    
