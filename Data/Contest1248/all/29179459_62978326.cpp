#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define nmax_def 110000
#define Cmax_def 2200
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	int N;
	cin >> N;
	rep(t, N) {
		ll n, m;
		ll epcount = 0;
		ll opcount = 0;
		ll eqcount = 0;
		ll oqcount = 0;
		cin >> n;
		vl p(n);
		rep(i, n) {
			cin >> p[i];
			if (p[i] % 2 == 0)
				epcount++;
			else
				opcount++;
		}
		cin >> m;
		vl q(m);
		rep(i, m) {
			cin >> q[i];
			if (q[i] % 2 == 0)
				eqcount++;
			else
				oqcount++;
		}
		ll ans = epcount * eqcount + opcount * oqcount;
		cout << ans << endl;
	}


	return 0;
}