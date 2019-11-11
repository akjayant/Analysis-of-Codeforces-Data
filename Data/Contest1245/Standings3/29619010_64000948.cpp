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
int t, n, r, p, s;
string a;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while(t--) {
		cin >> n >> r >> p >> s >> a;
		int can=0;
		vector<char> ans;
		rep(i, 0, n) {
			if (a[i] == 'R') {
				if (p) p--, can++, ans.pb('P');
				else ans.pb('X');
			}
			if (a[i] == 'P') {
				if (s) s--, can++, ans.pb('S');
				else ans.pb('X');
			}
			if (a[i] == 'S') {
				if (r) r--, can++, ans.pb('R');
				else ans.pb('X');
			}
		}
		if (can >= (n+1)/2) {
			cout << "YES" << endl;
			trav(c, ans) {
				if (c == 'X') {
					if (p) {
						p--; cout << 'P';
					} else if (r) {
						r--; cout << 'R';
					} else if (s) {
						s--; cout << 'S';
					}
				} else cout << c;
			}
 			cout << endl;
		} else cout << "NO" << endl;
	}
}
