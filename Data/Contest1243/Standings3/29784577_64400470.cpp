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

	int alp[26] = {};
	rep(i, n){
		alp[s[i]-'a']++;
		alp[t[i]-'a']++;
	}

	rep(i, 26){
		if(alp[i]%2){
			co("No");
			return;
		}
	}
	co("Yes");

	vector<P> pos;
	int cnt = 0;
	while(cnt < n){
		if(s[cnt] == t[cnt]){
			cnt++;
			continue;
		}
		FOR(i, cnt+1, n){
			if(s[i] == s[cnt]){
				swap(s[i], t[cnt]);
				pos.pb(mp(i+1, cnt+1));
				cnt++;
				continue;
			}
		}
		FOR(i, cnt+1, n){
			if(t[i] == s[cnt]){
				swap(s[cnt+1], t[i]);
				pos.pb(mp(cnt+2, i+1));
				swap(s[cnt+1], t[cnt]);
				pos.pb(mp(cnt+2, cnt+1));
				cnt++;
				continue;
			}
		}
	}

	co(pos.size());
	rep(i, pos.size()){
		cosp(pos[i].fs);
		co(pos[i].sc);
	}
}

int main(void){
	int k;
	cin >> k;

	rep(i, k) solve();

	return 0;
}
