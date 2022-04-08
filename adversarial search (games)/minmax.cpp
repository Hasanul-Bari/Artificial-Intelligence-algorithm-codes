#include<bits/stdc++.h>
using namespace std;

int a[10000];
int tree[30000];

int n,depth,branch;

int min_max(int node,int d,bool MaxPlayer)
{
    if(d==depth)
    {
        //cout<<node<<" ##"<<endl;
        return a[node];
    }

    if(MaxPlayer)
    {
        //cout<<max(min_max(node*2,d+1,false),min_max(node*2+1,d+1,false))<<" *"<<endl;

        return max(min_max(node*branch,d+1,false),min_max(node*branch+1,d+1,false));

    }
    else  ///minPlayer
    {
        //cout<<min(min_max(node*2,d+1,true),min_max(node*2+1,d+1,true))<<" **"<<endl;
        return min(min_max(node*branch,d+1,true),min_max(node*branch+1,d+1,true));

    }

}


int main()
{

    //cout<<"Enter the depth and branch";
    cin>>depth>>branch;

    n=round(pow(2,depth));

    //cout<<"Enter "<<n<<" leaf node values : "<<endl;

    for(int i=0; i<n; i++)
        cin>>a[i];


    cout<<min_max(0,0,true)<<endl;
}

/*
3 2
3 5 2 9 12 5 23 23
*/


/*
3 2
-1 8 -3 -1 2 1 -3 4
*/



/*
4 2
3 4 2 1 7 8 9 10 2 11 1 12 14 9 13 16
*/
