#include <bits/stdc++.h>
 
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
 
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define int long long
 
using namespace std;
typedef vector <int> vi;
typedef pair<int,int> pii;
inline void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}
 
char kam = 'R';
char noz = 'S';
char bum = 'P';
 
void solve() {
	int n;
	cin >> n;
	int k, b, no;
	cin >> k >> b >> no;
	string s;
	cin >> s;
	int cnt = 0;
	string ans = "";
	for(int i = 0; i < n; ++i) {
		ans += ' ';
	}
	for(int i = 0; i < n; ++i) {
		if(s[i] == kam) {
			if(b > 0) {
				b--;
				ans[i] = bum;
				cnt++;
			}
		}
		if(s[i] == bum) {
			if(no > 0) {
				no--;
				ans[i] = noz;
				cnt++;
			}
		}
		if(s[i] == noz) {
			if(k > 0) {
				k--;
				ans[i] = kam;
				cnt++;
			}
		}
	}
	if(cnt * 2 < n) {
		cout << "NO\n";
		return;
	}
	for(int i = 0; i < n; ++i) {
		if(ans[i] == ' ') {
			if(k > 0) {
				ans[i] = kam;
				k--;
			}
		}
		if(ans[i] == ' ') {
			if(b > 0) {
				ans[i] = bum;
				b--;
			}
		}
		if(ans[i] == ' ') {
			if(noz > 0) {
				ans[i] = noz;
				no--;
			}
		}
	}
	cout << "YES\n";
	cout << ans << "\n";
}
 
 
// #define lolipop
 
signed main() {
#ifdef lolipop
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
 
	fastio();
	int t; cin >> t; while(t--)solve();
 
}