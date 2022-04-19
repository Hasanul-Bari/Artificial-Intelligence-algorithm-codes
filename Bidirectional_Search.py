from collections import defaultdict, deque


def printpath(Fpath,Bpath):
    
    Fpath.pop()
    Bpath.reverse()
    path=Fpath+Bpath

    print(path)


def bidirectional(adj,src,goal):
    
    visited_forward=[]
    visited_backward=[]
    visited_forward.append(src)
    visited_backward.append(goal)
    
    forward_queue=deque()
    backward_queue=deque()
    forward_queue.append(src)
    backward_queue.append(goal)
    
    forward_path=defaultdict(list)
    backward_path=defaultdict(list)
    
    forward_path[src].append(src)
    backward_path[goal].append(goal)
    
    intersection=-1
    
    while len(forward_queue) and len(backward_queue):
    
        #forward BFS
        x=forward_queue.popleft()
        print("forward :",x)
        
    
        for node in adj[x]:
            if node not in visited_forward:
                visited_forward.append(node)
                forward_path[node]=forward_path[x]+[node]
                
                if node in visited_backward:
                    intersection=node
                    print(intersection)
                    break
                    
                forward_queue.append(node)
                
        
        if intersection!=-1:
            printpath(forward_path[intersection],backward_path[intersection])
            return
               
                
        #backward BFS
        x=backward_queue.popleft()
        print("backward :",x)
        
    
        for node in adj[x]:
            if node not in visited_backward:
                visited_backward.append(node)
                backward_path[node]=backward_path[x]+[node]
                
                if node in visited_forward:
                    intersection=node
                    print(intersection)
                    break
                    
                backward_queue.append(node)
                
                
        if intersection!=-1:
            printpath(forward_path[intersection],backward_path[intersection])
            return
            
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
    v=input("Start Node : ");
    u=input("End Node : ");
    
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


    
