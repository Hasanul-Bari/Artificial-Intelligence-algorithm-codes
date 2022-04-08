#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000];
int h[1000];
int vis[1000];
int p[1000];
int n,e;


class node
{
public:
    int n,h;

    node() {}

    node(int nn,int hh)
    {
        n=nn;
        h=hh;
    }
};

bool operator<(node a,node b)
{
    return b.h<a.h;
}

priority_queue <node> pq;


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


void best_first(int src,int dest)
{
    node nd(src,h[src]);


    pq.push(nd);

    while(!pq.empty())
    {
        node curr=pq.top();

        int x=curr.n;

        pq.pop();

        for(int i=0; i<adj[x].size(); i++)
        {
            int v=adj[x][i];

            if(vis[v]==false)
            {
                p[v]=x;

                vis[v]=true;

                pq.push({v,h[v]});

            }
        }
    }

    cout<<"Path : ";
    path(dest,src);
}

int main()
{
    //cout<<"Enter the number of nodes : ";
    cin>>n;
    //cout<<"Enter the number of edges : ";
    cin>>e;

    //cout<<"Enter "<<e<<" Edges : ";

    int u,v;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //cout<<"Enter heuristics value of "<<n<<" nodes : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>h[i];
    }

    int src,dest;
    cin>>src>>dest;

    best_first(src,dest);

}

/*
8 10
0 1
0 3
0 2
1 4
2 4
2 5
3 5
4 7
5 6
7 6
40 32 25 35 14 17 0 10
0 6
*/

/*
10 9
0 1
0 2
1 3
1 4
2 5
2 6
5 7
6 8
6 9
13 12 4 7 3 8 2 4 9 0
0 9
*/
