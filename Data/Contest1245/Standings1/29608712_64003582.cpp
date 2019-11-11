#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, a, b, c;
string s, t;
vector<char> v;

void solve() {
	v.clear();
	cin >> n;
	cin >> a >> b >> c;
	cin >> s;
	t = "";

	int r = 0, p = 0, S = 0;
	for(int i=0; i<n; i++) {
		if(s[i] == 'R') r++;
		if(s[i] == 'P') p++;
		if(s[i] == 'S') S++;
	}

	for(int i=0; i < b - r; i++) v.pb('P');
	for(int i=0; i < c - p; i++) v.pb('S');
	for(int i=0; i < a - S; i++) v.pb('R');

	int idx = 0;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		if(s[i] == 'R' && b > 0) {
			b--;
			t += "P";
			cnt++;
		}
		else if(s[i] == 'P' && c > 0) {
			c--;
			t += "S";
			cnt++;
		}
		else if(s[i] == 'S' && a > 0) {
			a--;
			t += 'R';
			cnt++;
		}
		else {
			if(v[idx] == 'R') a--;
			else if(v[idx] == 'P') b--;
			else c--;

			t += v[idx++];
		}
	}

	if(cnt >= (n+1)/2) {
		cout << "YES\n" << t << "\n";
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	fast;
	int t;
	cin >> t;

	while(t--) {
		solve();
	}
}