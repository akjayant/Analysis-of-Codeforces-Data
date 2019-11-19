#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;
typedef pair<pll, ll>plll;
typedef pair<int, ll>pil;

ll p[(int)1e5 + 10];
ll q[(int)1e5 + 10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i];

		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> q[i];

		ll evenP = 0;
		ll evenQ = 0;


		for (int i = 0; i < n; i++) {
			if (p[i] % 2 == 0) evenP++;
		}
		for (int i = 0; i < m; i++) {
			if (q[i] % 2 == 0) evenQ++;
		}

		ll ans = evenP * evenQ + (n - evenP) * (m - evenQ);
		cout << ans << "\n";
	}
}
