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
	vl a(N);
	rep(i, N) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), less <ll>());
	ll big_start = N / 2;
	ll short_len = 0;
	ll long_len = 0;
	rep(i, N) {
		if (i < big_start)
			short_len += a[i];
		else
			long_len += a[i];
	}
	short_len *= short_len;
	long_len *= long_len;
	ll ans = short_len + long_len;
	cout << ans << endl;

	return 0;
}