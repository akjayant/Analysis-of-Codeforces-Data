#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pii, int> para;
const int inf = 1e9 + 7;
const int maxN = 3e5 + 5;

int q, n, arr[maxN], lst[maxN], fst[maxN];
pii dp[maxN];
vector<pii> v;
string s;

int main() {
	cin >> q;
	REP(_, q) {
		cin >> n;
		cin >> s;
		int ans = -1;
		REP(i, s.size()) {
			if (s[i] == '1') {
				ans = i; break;
			}
		}
		FORD(i, s.size() - 1, 0) {
			if (s[i] == '1') {
				ans = min(ans, n - i - 1);
				break;
			}
		}
		//cout << "X " << ans << endl;
		if (ans == -1) cout << n << endl;
		else {
			cout << (n - ans) * 2 << endl;
		}
	}
	return 0;
}
