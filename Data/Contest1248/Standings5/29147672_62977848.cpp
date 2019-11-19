#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
#define minn(x,y) x=min(x,y)
#define maxx(x,y) x=max(x,y)
using namespace std;
int main()
{
	int i,j,k,n,m,t,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		y=0;
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x&1)
				y++;
			else
			{
				z++;
			}
		}
		scanf("%d",&m);
		int y1=0,z1=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			if(x&1)
			{
				y1++;
			}
			else
			{
				z1++;
			}
		}
		printf("%lld\n",1ll*y*y1+1ll*z*z1);
	}
}

