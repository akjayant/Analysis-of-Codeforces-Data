#include<bits/stdc++.h>
using namespace std;

#define db double
#define MAXN 2104
#define int long long
#define INF (int)0x3f3f3f3f3f3f3f3f

inline int read()
{
    register int x = 0 , ch = getchar();
    while( !isdigit( ch ) ) ch = getchar();
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
    return x;
}

int n,m;
int x[MAXN],y[MAXN];
int a[MAXN][MAXN];
int c[MAXN],d[MAXN];
int dis[MAXN];
int ls[MAXN];

int mabs(int x) {
	if(x < 0) return -x;
	return x;
}

void rd()
{
	cin >> n ;
	for(int i = 1; i <= n; i ++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	for(int i = 1; i <= n; i ++)
		cin >> d[i];
	
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) 
		if(i != j) {
			a[i][j] = (mabs(x[i]-x[j])+mabs(y[i]-y[j]))*(d[i]+d[j]);
		}
	}
	for(int i = 1; i <= n; i ++) {
		a[i][n+1] = a[n+1][i] = c[i];
	}
	n ++;
}

bool vis[MAXN];
bool p[MAXN][MAXN];

void prim()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 0;
	for(int i = 1; i <= n; i ++)
	{
		int u,v = INF;
		for(int j = 1; j <= n; j ++)
		if(!vis[j] && dis[j] < v) {
			v = dis[j];
			u = j;
		}
	//	cout<<u<<" "<<v<<"?\n";
		vis[u] = 1;
		for(int j = 1; j <= n; j ++) 
		if(!vis[j] && a[u][j] < dis[j]) {
			dis[j] = a[u][j];
			ls[j] = u;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += dis[i];
	cout<<ans<<"\n";
	
	for(int i = 2; i <= n; i ++) {
		p[i][ls[i]] = p[ls[i]][i] = 1;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++)
		if(p[i][n]) cnt ++;
	cout<<cnt<<"\n";
	for(int i = 1; i <= n; i ++)
		if(p[i][n]) cout<<i<<" ";
	cout<<"\n";
	cnt = 0;
	for(int i = 1; i < n; i ++)
		for(int j = 1; j < i; j ++)
		if(p[i][j]) {
			cnt ++;
		}	
	cout<<cnt<<"\n";
	for(int i = 1; i < n; i ++)
		for(int j = 1; j < i; j ++)
		if(p[i][j]) {
			cout<<i<<" "<<j<<"\n";
		}
	
}

signed main()
{
	rd();
	prim();
	return 0;
}
/*
3
2 3
1 1
3 2
3 2 3
3 2 3

4
1 4
3 3
4 4
2 1
14 12 9 13
2 3 1 2

*/