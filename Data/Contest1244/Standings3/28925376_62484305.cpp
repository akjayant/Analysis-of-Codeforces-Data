#include<bits/stdc++.h>
using namespace std;

#define ll long long

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    for(; ch < '0' || ch>'9'; ch = getchar())
        if(ch == '-') f = -f;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}

inline void chkmin( int &a, int b ) { if(a > b) a = b; }

inline void chkmax( int &a, int b ) { if(a < b) a = b; }

#define _ read()

#define ln endl

const int N = 1e5 + 5;
int n, id[N], cst[N][5], res[N], tmp[N];
ll f[N][5][5], g[N][5][5];
vector < int > G[N];

int main()
{
	n = _;
	for( int j = 1; j <= 3; j++ ) 
		for( int i = 1; i <= n; i++ ) 
			cst[i][j] = _;
	for( int i = 1; i < n; i++ ) 
	{
		int u = _, v = _;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int pos = 0;
	for( int i = 1; i <= n; i++ ) 
		if(G[i].size() > 2)
			return puts("-1"), 0; 
		else
		if(G[i].size() == 1) 
			pos = i;
	// cout << pos << ln;
	for( int i = 1; i <= n; i++ ) 
	{
		id[i] = pos;	
		// cout << pos << ln;
		if(i == n) break;
		if(G[pos][0] == id[i - 1])
			pos = G[pos][1];
		else
			pos = G[pos][0];
	}
	// for( int i = 1; i <= n; i++ ) 
	// 	cout << id[i] << " ";
	// cout << ln;
	for( int i = 1; i <= n; i++ )
		for( int j = 1; j <= 3; j++ )
			for( int k = 1; k <= 3; k++ ) 
				f[i][j][k] = 2e18;
	// for( int i = 2; i <= n; i++ ) 
		for( int j = 1; j <= 3; j++ )
			for( int k = 1; k <= 3; k++ ) 
				f[2][j][k] = cst[id[1]][j] + cst[id[2]][k];
	for( int i = 3; i <= n; i++ )
		for( int j = 1; j <= 3; j++ )
			for( int k = 1; k <= 3; k++ )
				for( int l = 1; l <= 3; l++ ) 
				if(j != k && k != j && j != l) 
				{
					if(f[i - 1][j][k] + cst[id[i]][l] < f[i][k][l])
						f[i][k][l] = f[i - 1][j][k] + cst[id[i]][l],
						g[i][k][l] = j;
				}
	ll ans = 2e18;
	int p, q;
	for( int i = 1; i <= 3; i++ ) 
		for( int j = 1; j <= 3; j++ ) 
			if(i != j && f[n][i][j] < ans) 
				ans = f[n][i][j], p = i, q = j;
	cout << ans << ln;

	// cout << f[n][p][q] << ln;

	// cout << p << " " << q << ln;

	// cout << g[n][3][1] << ln;
	// cout << q << ln;
	for( int i = n, t; i >= 3; i-- )
		res[i] = q, t = g[i][p][q], q = p, p = t;
	res[2] = q; res[1] = p;
	// for( int i = 1; i <= n; i++ ) 
	// 	cout << res[i] << " ";
	for( int i = 1; i <= n; i++ ) 
		tmp[id[i]] = res[i];
	for( int i = 1; i <= n; i++ ) 
		cout << tmp[i] << " "; 
}	