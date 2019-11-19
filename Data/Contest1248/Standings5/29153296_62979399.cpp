#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <bitset>
#include <set>

#define all(x) x.begin(), x.end()

#pragma GCC optmize("Ofast,unroll-loops,fast-math,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,mmx,abm,popcnt,tune=native")

using namespace std;

typedef long long ll;

const ll inf = (ll)1e18 + 228;
const ll cst = 1e5 + 5;

ll n;

vector<ll> vc;

int main() {
	cin >> n;
	vc.resize(n);
	for (int i = 0; i < n; i++) cin >> vc[i];
	sort(all(vc));
	ll a = 0, b = 0;
	for (int i = 0; i < n / 2; i++) a += vc[i];
	for (int i = n / 2; i < n; i++) b += vc[i];
	cout << a*a + b*b;
	return 0;
}
/*

baaabbaaab
bab
*/