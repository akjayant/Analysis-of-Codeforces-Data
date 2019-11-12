#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define P push
#define mem(x,y) memset(x,y,sizeof(x))
vector<int> vc[500];
int num[100000];
int main()
{
    int i,j,k,s,d,r,m,n;
    cin>>n;

    s=0;
    d=1;
    m=n*n;
    for(i=1;i<=n*2;i++)
    {
        if(i<=n) num[i]=i;
        else num[i]=(2*n)-i+1;

        //cout<<num[i]<<endl;
    }

    j=1;
    for(i=1; i<=m; i++)
    {
        //cout<<num[j]<<endl;
       vc[num[j]].PB(i);
       j++;
       if(j>2*n) j=1;
    }

    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++) cout<<vc[i][j]<<" ";
        cout<<endl;
    }

}

