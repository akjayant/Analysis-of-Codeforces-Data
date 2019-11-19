#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cassert>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<deque>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string.h>
#include<string>
#include<iomanip>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FOR(i,k,n) for(int i = k ; i < n ; ++i)
#define REP(i,k,n) for(int i = k ; i <= n ; ++i)
#define sz(x) (int)x.size()
#define VAR(x) #x << " " << x
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;

// static const int N;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = n;
	int left = -1, right = -1;
	for (int i = 0; i < n; ++i) {
		// if (s[i] == '1') right = i;
		// if (s[i] == '1' && left != -1) left  = i;
		if (s[i] == '1') {
			ans = max(ans, i+1 + i+1);
			ans = max(ans, i+1 + n-i);
			ans = max(ans, n-i + n-i);
		}
	}
	cout << ans << "\n";
}

int main() {
	boost;
	int t;
	cin >> t;
	while(t--) solve();
}