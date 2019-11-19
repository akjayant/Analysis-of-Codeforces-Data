#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <sstream>

using namespace std;

#define ll long long
#define ld long double
const int inf = 1000000007;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	vector <ll> dels;

	ll k = n;
	map <ll, ll> mp;

	for (ll i = 2; i*i <= k && n > 1; i++) {
		if (n % i == 0) {
			mp[i]++;
			dels.push_back(i);
			while (n % i == 0) {
				n /= i;
			}
			if ( n > 1 ) {
				mp[n] ++;
			}
		}
	}
	


	if (mp.size() == 0) {
		cout << k;
	}
	else if (mp.size() == 1) {
		cout << dels[0];
	}
	else cout << 1;
	return 0;
}

