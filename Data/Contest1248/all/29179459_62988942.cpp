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

vector<vl> anslist(nmax_def);

void DP(void) {
	vl ansini;
	ansini.push_back(2); // diff
	ansini.push_back(0); // same
	anslist[0] = ansini;
	rep(i, nmax_def - 1) {
		vl anstmp;
		anstmp.push_back(anslist[i][0] + anslist[i][1]); // diff
		anstmp.push_back(anslist[i][0]); // same
		anstmp[0] %= mod;
		anstmp[1] %= mod;
		anslist[i + 1] = anstmp;
	}
	return;
}

int main() {
	ll n, m;
	cin >> n >> m;
	DP();
	n--;
	m--;
	ll ans = anslist[n][0] + anslist[n][1] + anslist[m][0] + anslist[m][1];
	ans += mod;
	ans -= 2;
	ans %= mod;
	cout << ans << endl;
	return 0;
}