#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n,m,fa[100100],vis[100100],ans=0;
vector<int> sq[100100];
queue<int> q;
int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int find(int x)
{
	if (fa[x]==x) return fa[x];
	fa[x]=find(fa[x]);
	return fa[x];
}

void bfs(int st)
{
	q.push(st);vis[st]=1;ans++;
	while (!q.empty())
	{
		int u=q.front();q.pop();
		int len=sq[u].size();
		rep(i,0,len-1)
		{
			int v=sq[u][i];
			vis[v]=u;
		}
		for (int i=find(1);i<=n;i=find(i+1))
			if (vis[i]!=u) 
			{
				fa[i]=find(i+1);q.push(i);
			}
	}
}

int main()
{
	n=read();m=read();
	rep(i,1,m)
	{
		int u=read(),v=read();
		sq[u].pb(v);sq[v].pb(u);
	}
	rep(i,1,n+1) fa[i]=i;
	for (int i=1;i<=n;i=find(i+1)) bfs(i);
	printf("%d",ans-1);
	return 0;
}

