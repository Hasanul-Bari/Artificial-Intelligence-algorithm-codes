#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1000],cost[1000];
int h[1000],f[1000],g[1000];
int p[1000];
int n,e;



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


void astar(int src,int dest)
{

    for(int i=0; i<n; i++)
    {
        g[i]=INT_MAX;
        f[i]=INT_MAX;
    }
    g[src]=0;
    f[src]=g[src]+h[src];


    priority_queue< pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;   //first f(n) , second node

    pq.push({f[src],src});



    while(!pq.empty())
    {
        auto x=pq.top();

        int curr=x.second, currF=x.first;

        //cout<<currF<<" x "<<curr<<endl;

        pq.pop();

        for(int i=0; i<adj[curr].size(); i++)
        {
            int v=adj[curr][i];
            int c=cost[curr][i];

            if(g[curr]+c+h[v]<f[v])
            {
                p[v]=curr;

                g[v]=g[curr]+c;
                f[v]=g[v]+h[v];

                //cout<<f[v]<<" "<<g[v]<<" "<<h[v]<<" * "<<v<<endl;

                pq.push({f[v],v});

            }
        }
    }

    cout<<"Path : ";
    path(dest,src);

    cout<<endl<<f[dest]<<endl;
}

int main()
{
    //cout<<"Enter the number of nodes : ";
    cin>>n;
    //cout<<"Enter the number of edges : ";
    cin>>e;

    //cout<<"Enter "<<e<<" Edges : ";

    int u,v,z;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>z;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[u].push_back(z);
        cost[v].push_back(z);
    }

    //cout<<"Enter heuristics value of "<<n<<" nodes : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>h[i];
    }

    int src,dest;
    cin>>src>>dest;

    astar(src,dest);

}

/*
7 9
0 1 4
0 2 3
1 4 5
1 5 12
2 5 10
2 3 7
3 5 2
4 6 16
5 6 5
14 12 11 6 11 4 0
0 6
*/

/*
Path : 0 2 3 5 6
17
*/


/*
10 14
0 1 6
1 2 3
1 3 2
2 3 1
2 4 5
3 4 8
0 5 3
5 6 1
5 7 7
6 8 3
7 8 2
8 4 5
8 9 3
4 9 5
10 8 5 7 3 6 5 3 1 0
0 9
*/

/*
Path : 0 5 6 8 9
10
*/















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

