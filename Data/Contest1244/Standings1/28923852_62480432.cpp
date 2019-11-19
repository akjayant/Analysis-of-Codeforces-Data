#define _CRT_SECURE_NO_WARNINGS

/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/

#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <math.h>
#include <bitset>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <stack>
#include <random>
#include <tuple>
#include <string.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pp;
typedef tuple<int, int, int> tt;
typedef unsigned int ui;

const int inf = (int)1e9;
const int mod = inf + 7;
//const int mod = 998244353;
//const ll inf = (ll)1e18;

#define umap unordered_map
#define Power ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()

int main() {

	Power;

	ll n, p, d, w;
	cin >> n >> p >> w >> d;


	for (ll a = 0; a < w; a++) {
		ll x = (p - d * a) / w;
		ll y = a;
		ll z = n - x - y;
		if (z < 0 || x < 0 || y < 0 || x*w + y*d != p)
			continue;
		else {
			cout << x << " " << y << " " << z;
			return 0;
		}
	}

	cout << -1;

	return 0;
}