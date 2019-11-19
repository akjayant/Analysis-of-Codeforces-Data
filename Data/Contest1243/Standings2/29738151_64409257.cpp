// https://codeforces.com/contest/920/submission/34851685

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ft first
#define sd second
#define pb push_back
using namespace std;
const ll mod = 1e9+7;
ll power(ll a, ll b, ll m = mod) {
    ll x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}

// const int N = 1e6+9;
// int a[N];


set<int> a[200020];
vector<int> z;
int n, m;
set<int> s;
int dfs(int i) {
	int sz = 1;
	for (set<int>::iterator it = s.begin(); it != s.end(); ) {
		if (a[i].count(*it) == 0) {
			int x = *it;
			s.erase(x);
			sz += dfs(x);
			it = s.lower_bound(x);
		} else {
			it++;
		}
	}
	return sz;
}

signed main() {  
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
    
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		// scanf("%d%d", &x, &y);
		a[x].insert(y);
		a[y].insert(x);
	}
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	while (s.size()) {
		int x = *s.begin();
		s.erase(x);
		z.push_back(dfs(x));
	}
	cout << (int)z.size()-1 << "\n";



    return 0;
    
}
