#include<bits/stdc++.h>
using namespace std;

int a[10000];

int n,depth,branch;

int alpha_beta(int node,int d,bool MaxPlayer,int alpha,int beta)
{
    if(d==depth)
    {
        //cout<<node<<" ##"<<endl;
        return a[node];
    }

    if(MaxPlayer)
    {
        int bestMax=INT_MIN;

        for(int i=0; i<branch; i++)
        {
            int x=alpha_beta(node*branch+i,d+1,false,alpha,beta);
            bestMax=max(bestMax,x);
            alpha=max(alpha,bestMax);


            if(beta<=alpha)
                break;
        }

        return bestMax;
    }
    else  ///minPlayer
    {
        int bestMin=INT_MAX;

        for(int i=0; i<branch; i++)
        {
            int x=alpha_beta(node*branch+i,d+1,true,alpha,beta);

            bestMin=min(bestMin,x);
            beta=min(beta,bestMin);


            if(beta<=alpha)
                break;
        }

        return bestMin;

    }

}


int main()
{

    //cout<<"Enter the depth and branch";
    cin>>depth>>branch;

    n=round(pow(branch,depth));

    //cout<<"Enter "<<n<<" leaf node values : "<<endl;

    for(int i=0; i<n; i++)
        cin>>a[i];


    cout<<alpha_beta(0,0,true,INT_MIN,INT_MAX)<<endl;
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

/*
2 3
3 12 8 2 4 6 14 5 2
*/

