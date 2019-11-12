#include <bits/stdc++.h>
using namespace std;

#define FOR(i, m, n) for(int (i) = (m); (i) < (n); (i)++)
#define FORN(i, m, n) for(int (i) = (m); (i) <= (n); (i)++)
#define FORR(i, m, n) for(int (i) = (m); (i) >= (n); (i)--)
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define repr(i, n) FORR(i, n, 0)
#define repnr(i, n) FORR(i, n, 1)
#define co(n) cout << (n) << endl
#define cosp(n) cout << (n) << ' '
#define setp(n) cout << fixed << setprecision(n);
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1e9+1;
const ll LINF = 1e18+1;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const double PI = acos(-1);
const double EPS = 1e-9;

void solve(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	vector<int> dif_pos;
	rep(i, n) if(s[i] != t[i]) dif_pos.pb(i);

	if(dif_pos.empty()) co("Yes");
	else if(dif_pos.size() == 2){
		int pos1 = dif_pos[0], pos2 = dif_pos[1];
		if(s[pos1] == s[pos2] && t[pos1] == t[pos2]) co("Yes");
		else co("No");
	}else co("No");
}

int main(void){
	int k;
	cin >> k;

	rep(i, k) solve();

	return 0;
}
