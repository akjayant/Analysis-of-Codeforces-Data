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
int a[100010];
int main()
{
	int i,j,k,n,m,x,y,z;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	reverse(a,a+n);
	x=0;y=0;
	for(i=0;i<(n+1)/2;i++)
	{
		x+=a[i];
	}
	for(;i<n;i++)
	{
		y+=a[i];
	}
	printf("%lld",1ll*x*x+1ll*y*y);
}
