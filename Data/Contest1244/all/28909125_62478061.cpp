#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define int long long
#define MAXN 200005
#define INF 0x3f3f3f3f

int n,m;
int c[5][MAXN];
int a[MAXN];
struct bian
{
	int x,y,ls;
}b[MAXN];
int cnt,t[MAXN];
int du[MAXN];

void jb(int x,int y)
{
	cnt ++;
	b[cnt].x = x;
	b[cnt].y = y;
	b[cnt].ls = t[x];
	t[x] = cnt;
}

void rd()
{
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> c[1][i];
	for(int i = 1; i <= n; i ++) cin >> c[2][i];
	for(int i = 1; i <= n; i ++) cin >> c[3][i];
	for(int i = 1; i <  n; i ++) {
		int x,y;
		x = i; y = x+1;
		cin >> x >> y;
		jb(x,y);
		jb(y,x);
		du[x] ++;
		du[y] ++;
	}
}

int rot;
int nn = 0;
int fa[MAXN];

void dfs(int x)
{
//	if(x%1000 == 0)cout<<x<<"\n";
	nn ++;
	a[nn] = x;
	for(int i = t[x]; i != 0; i = b[i].ls) {
		int y = b[i].y;
		if(y != fa[x]) {
			fa[y] = x;
			dfs(y);
		}
	}
}

int d[MAXN];
int an[MAXN];

int get(int x,int y)
{
	int ans = 0;
	d[1] = x; d[2] = y;
	for(int i = 3; i <= n; i ++) {
		for(int l = 1; l <= 3; l ++)
		if(l != d[i-1] && l != d[i-2]) {
			d[i] = l;
		}
	}
	for(int i = 1; i <= n; i ++)
		ans += c[d[i]][a[i]];
	return ans;
}

int ans = (int)INF*INF;

signed main()
{
	rd();
	for(int i = 1; i <= n; i ++)
		if(du[i] >= 3)
		{
			cout<<-1;
			return 0;
		}
	for(int i = 1; i <= n; i ++)
	if(du[i] == 1) {
		rot = i;
	}
	dfs(rot);
/*	for(int i = 1; i <= n; i ++)
		cout<<a[i]<<" ";
	cout<<"\n";
*/	for(int i = 1; i <= 3; i ++)
		for(int j = 1; j <= 3; j ++)
		if(i != j)
		{
			int p = get(i,j);
		//	cout<<p<<" "<<ans<<"?\n";			
			if(p < ans) {
		//		cout<<"???\n";
				for(int i = 1; i <= n; i ++)
					an[a[i]] = d[i];
			}
			ans = min(ans,p);
		}
	cout<<ans<<"\n";
	for(int i = 1; i <= n; i ++)
		cout<<an[i]<<" ";
	return 0;
}
/*
10
5 3 4 3 2 5 7 1 4 3
1 5 2 1 4 5 2 2 3 1
7 6 2 5 4 3 2 5 3 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9 
9 10

1 8
7 1
7 10
10 3
5 8
2 5
4 6
3 4
9 2
*/