#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

typedef long long ll;
#define READ(a) int a; cin >> a;
#define READARR(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define READMAT(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const ll inf = 1e18;
const ll mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	READ(n);
	int c[n + 1][3];
	FOR (i, 1, n) cin >> c[i][0];
	FOR (i, 1, n) cin >> c[i][1];
	FOR (i, 1, n) cin >> c[i][2];
	
	vi adj[n + 1];
	FOR (i, 2, n)
	{
	    int x, y;
	    cin >> x >> y;
	    adj[x].pb(y);
	    adj[y].pb(x);
	}
	
	int leaf;
	FOR (i, 1, n) 
	    if (adj[i].size() > 2)
	        {cout << -1; return 0;}
	        
	    else if (adj[i].size() == 1)
	        leaf = i;
	
	int m[n + 1], cur = leaf, prev = 0;
	m[1] = leaf;
	
	FOR (i, 2, n)
	{
	    int j;
	    if (adj[cur][0] != prev) j = adj[cur][0];
	    else j = adj[cur][1];
	    m[i] = j;
	    prev = cur;
	    cur = j;
	}
	
	int dp[n + 1][3][3] = {};
	FOR (i, 0, 2)
	    FOR (j, 0, 2)
	        dp[2][i][j] = c[m[2]][i] + c[m[1]][j];
	
	FOR (i, 3, n)
	{
	    dp[i][0][1] = dp[i - 1][1][2] + c[m[i]][0];
	    dp[i][0][2] = dp[i - 1][2][1] + c[m[i]][0];
	    
	    dp[i][1][0] = dp[i - 1][0][2] + c[m[i]][1];
	    dp[i][1][2] = dp[i - 1][2][0] + c[m[i]][1];
	    
	    dp[i][2][0] = dp[i - 1][0][1] + c[m[i]][2];
	    dp[i][2][1] = dp[i - 1][1][0] + c[m[i]][2];
	}
	
	int f, s, mn = inf;
	FOR (i, 0, 2)
	    FOR (j, 0, 2)
	    {
	        if (i == j) continue;
	        if (mn > dp[n][i][j]) mn = dp[n][i][j], f = i, s = j;
	    }
	
	cout << mn << endl;
	int col[n + 1];
	
	col[m[n]] = f, col[m[n - 1]] = s;
	FORD (i, n - 2, 1)
	{
	    int x;
	    FOR (j, 0, 2) if (f != j && s != j) x = j;
	    col[m[i]] = x;
	    f = s;
	    s = x;
	}
	
	FOR (i, 1, n) cout << col[i] + 1 << " ";
}
