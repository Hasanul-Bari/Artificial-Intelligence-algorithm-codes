#include<bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
int n,e;

bool visited_forward[1000];
bool visited_backward[1000];

int pf[1000],pb[1000];

void path(int u,int s)
{
    if(u==s)
    {
        cout<<u<<" ";
        return;
    }

    path(pf[u],s);
    cout<<u<<" ";
}

void path2(int s,int d)
{
    while(s!=d)
    {
        s=pb[s];
        cout<<s<<" ";
    }
}




void bidirection(int src,int dest)
{

    queue <int> qf,qb;

    visited_forward[src]=true;
    visited_backward[dest]=true;

    //level[src]=0;
    //p[src]=-1;

    qf.push(src);
    qb.push(dest);

    while(!qf.empty() && !qb.empty())
    {
        ///forward bfs

        int x=qf.front();
        qf.pop();
        cout<<x<<" for"<<endl;

        for(int i=0; i<adj[x].size(); i++)
        {
            int y=adj[x][i];
            if(visited_forward[y]==false)
            {
                visited_forward[y]=true;
                pf[y]=x;
                qf.push(y);

                if(visited_backward[y]==true)
                {
                    cout<<"Intersected at "<<y<<endl;
                    cout<<"Path : ";
                    path(y,src);
                    path2(y,dest);
                    return;
                }
            }


        }


        ///backward bfs
        x=qb.front();
        qb.pop();
        cout<<x<<" back"<<endl;

        for(int i=0; i<adj[x].size(); i++)
        {
            int y=adj[x][i];
            if(visited_backward[y]==false)
            {
                visited_backward[y]=true;
                pb[y]=x;
                qb.push(y);

                if(visited_forward[y]==true)
                {
                    cout<<"Intersected at -"<<y<<endl;
                    cout<<"Path : ";
                    path(y,src);
                    path2(y,dest);
                    return;
                }
            }


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

    bidirection(src,dest);

    return 0;
}


/*
15 14
0 4
1 4
2 5
3 5
4 6
5 6
6 7
7 8
8 9
8 10
9 11
9 12
10 13
10 14
*/
