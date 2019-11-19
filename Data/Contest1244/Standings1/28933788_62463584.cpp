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
const int maxN = 5e6 + 5;

int q, a, b, c, d, k;

int main() {
	cin >> q;
	REP(_, q) {
		cin >> a >> b >> c >> d >> k;
		int x = a / c;
		if (a % c != 0) x++;
		int y = b / d;
		if (b % d != 0) y++;
		if (x + y > k) cout << -1 << endl;
		else cout << x << " " << y << endl;
	}
	return 0;
}
