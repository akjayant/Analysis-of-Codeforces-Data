#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <string.h>
using namespace std;
long long l,r;
long long DP[35][5][5][5][5]={0};
bool have[35][5][5][5][5]={0};
long long F(long long here,long long x,long long y,long long a,long long b)
{

    bool m=1,n=1,o=1;
    int xx,yy,aa,bb;
    if(here==-1) return 1;
    if(have[here][x][y][a][b]) return DP[here][x][y][a][b];
    have[here][x][y][a][b]=1;
    DP[here][x][y][a][b]=0;
    if(x==0)
    {
        if((l&(1<<here)))
        {
            m=0;
            o=0;
        }
    }

    if(a==0)
    {
        if((l&(1<<here)))
        {
            m=0;
            n=0;
        }
    }

    if(y==0)
    {
        if((r&(1<<here))==0)
        {
            n=0;
        }
    }

    if(b==0)
    {
        if((r&(1<<here))==0)
        {
            o=0;
        }
    }

    if(m)
    {
       if((r&(1<<here))==0) DP[here][x][y][a][b]=F(here-1,x,y,a,b);
       else DP[here][x][y][a][b]=F(here-1,x,1,a,1);
    }

    if(n)
    {
        xx=x;
        bb=b;
        if((l&(1<<here))==0) xx=1;
        if((r&(1<<here))) bb=1;
        DP[here][x][y][a][b]+=F(here-1,xx,y,a,bb);

    }

    if(o)
    {
        yy=y;
        aa=a;
        if((l&(1<<here))==0) aa=1;
        if((r&(1<<here))) yy=1;
        DP[here][x][y][a][b]+=F(here-1,x,yy,aa,b);

    }
    return DP[here][x][y][a][b];

}
int main()
{
	long long T,ans=0,i,j;
	scanf("%lld",&T);
	while(T--)
    {
        ans=0;
        memset(have,0,sizeof(have));
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",F(30,0,0,0,0));
    }
	return 0;
}
