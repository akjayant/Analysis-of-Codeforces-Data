#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int N=5e6+10;
const ll mod=1e9+7;
double dp1[150];
double dp2[150];
int takeid(int x,int y)
{
    if(x&1) return y+(x-1)*10;
    else return (10-y+1)+(x-1)*10;
}
int tp[105];
int g[15][15];
int main()
{
    for(int i=10; i>=1; --i)
    {

        for(int j=1; j<=10; ++j)
        {
            int id=takeid(i,j);
//            printf("id:%d ",id);
            scanf("%d",&g[i][j]);
            if(g[i][j]==0) tp[id]=-1;
            else tp[id]=takeid(i+g[i][j],j);
        }
        puts("");
    }
    dp1[100]=0;
    dp2[100]=0;//use
    for(int i=99; i>=1; --i)
    {
        dp1[i]=dp2[i]=0;
        double sum=0;
        int k=min(6,100-i);
        for(int j=1; j<=k; ++j)
            sum+=dp2[i+j];
        dp1[i]=(sum+6.0)/k;
        dp2[i]=dp1[i];
        if(tp[i]!=-1)
        {
            dp2[i]=min(dp2[i],dp1[tp[i]]);
        }
    }
    printf("%.10f\n",dp2[1]);
    return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

*/
