#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long ll;
typedef pair<ll, ll> pll;

//最大公約数
//O(log max(a,b))
template<class T>
T GCD(T a, T b) {
	if (b == 0)return a;
	return GCD(b, (T)(a % b));
}


int main() {
	ll T;
	cin >> T;
	for (ll t = 0; t < T; t++) {
		ll a, b;
		cin >> a >> b;
		ll g = GCD(a, b);
		if (g == 1)cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	return 0;
}