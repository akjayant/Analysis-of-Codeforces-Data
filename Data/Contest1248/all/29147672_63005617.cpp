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
int mod=1e9+7;
int main()
{
	int i,j,k,x,y,z,n,m;
	scanf("%d%d",&n,&m);
	a[1]=2;
	a[2]=4;
	if(n<m)
	{
		swap(n,m);
	}
	for(i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
		a[i]=a[i]%mod;
	}
	printf("%d",(a[n]+a[m]-2)%mod);
}
