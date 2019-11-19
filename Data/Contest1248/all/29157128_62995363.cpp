#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
 
using namespace std;

#define fo(i, a, b) for(int i = a; i <= b; i++)
#define _fo(i, a, b) for(int i = a; i >= b; i--)
#define foa(i, a) for (auto &i : a)
#define sz(a) ((int) a.size())
#define all(a) begin(a), end(a)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mk(x, y) make_pair(x, y)  

typedef int64_t ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5+5;
const int MOD = 1e9+7;
const ll INF = INT_MAX;
const ll _INF = INT_MIN;

int n;
ll l = 0, h = 0;
ll a[MAX];

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	fo(i, 1, n) cin >> a[i];
	
	sort(a+1, a+n+1);
	_fo(i, n, 1) {
		if(i > n/2) l += a[i];
		else h += a[i];
	}
	
	cout << (h*h)+(l*l);
}