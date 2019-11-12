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

vector<vl> pow_;
vi plist;
void pow_ini() {
	int len = plist.size();
	rep(i, len) {
		ll ptmp = plist[i];
		vl powtmp;
		powtmp.push_back(ptmp);
		rep(j, 62) {
			ll nxt = powtmp[j] * powtmp[j];
			nxt %= mod;
			powtmp.push_back(nxt);
		}
		pow_.push_back(powtmp);
	}
	return;
}

ll pow1(ll i, ll b) {
	ll ans = 1;
	rep(n, 62) {
		if ((b >> n) % 2 == 1) {
			ans *= pow_[i][n];
			ans %= mod;
		}
	}
	return ans;
}

int main() {
	ll N, M;
	cin >> N >> M;
	ll ans;
	plist.push_back(2);
	pow_ini();
	ans = pow1(0, M);
	ans--;
	ans += mod;
	ans %= mod;
	plist[0] = ans;
	pow_ini();
	ans = pow1(1, N);
	cout << ans << endl;



	return 0;
}