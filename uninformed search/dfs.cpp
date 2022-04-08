#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
int n,e;

bool visited[1000];
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

void dfs(int src)
{
    visited[src]=true;
    cout<<src<<endl;

    for(int i=0; i<adj[src].size(); i++)
    {
        int x=adj[src][i];
        //cout<<"x"<<endl;
        if(visited[x]==false)
        {
            p[x]=src;
            dfs(x);
        }

    }
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

    for(int i=1; i<=n; i++)
    {
        if(visited[i]==false)
            dfs(i);
    }

    cout<<"Path : ";
    path(dest,src);


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
