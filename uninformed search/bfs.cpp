#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
int n,e;

bool visited[1000];
int level[1000];
int p[1000];

void path(int u,int s)
{
    if(u==s)
    {
        cout<<u<<" ";
        return;
    }


    path(p[u],s);
    cout<<u<<" ";
}




void bfs(int src,int dest)
{

    queue <int> q;

    visited[src]=true;
    level[src]=0;
    //p[src]=-1;

    q.push(src);

    while(!q.empty())
    {
        int x=q.front();
        cout<<x<<endl;
        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int y=adj[x][i];
            if(visited[y]==false)
            {
                visited[y]=true;
                level[y]=level[x]+1;
                p[y]=x;
                q.push(y);
            }
        }
    }


    for(int i=1; i<=n; i++)
        cout<<i<<" "<<level[i]<<endl;

    cout<<"Path : ";
    path(dest,src);
}




int main()
{

    //cout<<"Enter the number of nodes : ";
    cin>>n;
    //cout<<"Enter the number of edges : ";
    cin>>e;

    //cout<<"Enter "<<e<<" edges : ";

    int u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src,dest;
    cin>>src>>dest;

    bfs(src,dest);

    return 0;
}


/*
8 8

1 2
1 3
1 4
2 5
2 6
3 7
3 8
4 8

1 8
*/
