#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll ((ll) 1e18 + 10)

#define endl '\n'
#define fi first
#define se second
#define pb emplace_back
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a)-1; i >= (b); i--)

const int N = 100010;
int T, n;
string s, t;

bool f() {
	vector<pii> ans;
	rep(i, 0, n) if (s[i] != t[i]) {
		if (i == n-1) return false;
		bool flag=false;
		rep(j, i+1, n) if (s[j] == s[i]) {
			ans.pb(j, i);
			swap(s[j], t[i]);
			flag=true;
			break;
		}
		if (flag) continue;
		rep(j, i+1, n) if (t[j] == s[i]) {
			ans.pb(i+1, j);
			ans.pb(i+1, i);
			swap(s[i+1], t[j]);
			swap(s[i+1], t[i]);
			flag=true;
			break;
		}
		if (!flag) return false;
	}
	cout << "YES" << endl;
	cout << sz(ans) << endl;
	trav(p, ans) cout << p.fi+1 << " " << p.se+1 << endl;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while(T--) {
		cin >> n >> s >> t;
		if (!f()) cout << "No" << endl;
	}
}
