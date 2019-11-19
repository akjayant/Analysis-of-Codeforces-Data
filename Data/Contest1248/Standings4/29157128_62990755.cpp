#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fo(i, a, b) for(int i = a; i <= b; i++)
#define _fo(i, a, b) for(int i = a; i >= b; i--)
#define sz(a) ((int) a.size())
#define all(a) begin(a), end(a)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mk(x, y) make_pair(x, y)  
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 1e5+5;
const int MOD = 1e9+7;
const ll INF = INT_MAX;
const ll _INF = INT_MIN;

int n, m;
ll total[MAX];

void precompute(int temp) {
	total[0] = 1;
	total[1] = 1;
	fo(i, 2, temp) total[i] = (total[i-1]+total[i-2]) % MOD;
}

ll solve() {
	ll curr_2 = (2 * ((total[n]-1) + MOD)) % MOD;
	ll curr_1 = (2 * total[m]) % MOD;
	return (curr_1+curr_2) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	precompute(max(n, m));
	cout << solve();
}