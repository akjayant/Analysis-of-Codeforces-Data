//                             In The Name Of Allah
#include <bits/stdc++.h>
#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long long
using namespace std; 
 
const int N = 1e6 + 100, OO = 1e18, M = 1e9 + 7, P = 6151, sq = 360, lg = 23;
typedef pair <int, int> pii;
int c[N][10], ran[N];
vector <int> v[N];

int dfs(int x, int y, int c1, int c2) {
	int cnt = c[x][c1];
	ran[x] = c1;
	for(auto u : v[x]) {
		if(u == y)
			continue;
		int t1 = 0, t2 = 0, t3 = 0;
		if(c1 == 1 || c2 == 1)	
			t1 = 1;
		if(c1 == 2 || c2 == 2)
			t2 = 1;
		if(c1 == 3 || c2 == 3)
			t3 = 1;
		if(t1 == 0)
			cnt += dfs(u, x, c2, 1);
		else if(t2 == 0)
			cnt += dfs(u, x, c2, 2);
		else
			cnt += dfs(u, x, c2, 3);
	}	
	return cnt;
}

int32_t main() {
    use_fast;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
    	cin >> c[i][1];
    for(int i = 1; i <= n; i++)
    	cin >> c[i][2];
    for(int i = 1; i <= n; i++)
    	cin >> c[i][3];
    for(int i = 0; i < n - 1; i++) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
	}
	int st = 0;
	for(int i = 1; i <= n; i++) {
		if(v[i].size() >= 3) 
    		return cout << -1, 0;
    	if(v[i].size() == 1)
    		st = i;
	}
	int ans = OO;
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			if(i == j)
				continue;
			ans = min(ans, dfs(st, 0, i, j));
		}
	}
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			if(i == j)
				continue;
			if(ans == dfs(st, 0, i, j)) {
				cout << ans << endl;
				for(int i = 1; i <= n; i++)
					cout << ran[i] << " ";
				return 0;
			}
		}
	}
	return 0;
} 
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/
