//#define _CLIBCXX_DEBAG
//#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdint>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <limits>
#include <cstdio>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <ctime>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pi acos(-1.0)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

constexpr auto inf = 1e9;
constexpr auto eps = 1e-9;

typedef double db;
typedef long long ll;

ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= 1000000007;
		}
		a *= a;
		a %= 1000000007;
		n >>= 1;
	}
	return res;
}

void solve() {
	int n, m=1;
	cin >> n;
	vector<vector<int > > v(n, vector<int >(n));
	for (int j = 0; j < n; j++)
		if(j & 1)
			for (int i = 0; i < n; i++)
				v[j][i] = m++;
		else
			for (int i = n-1; i >=0; i--)
				v[j][i] = m++;
	for (int j = 0; j < n; j++, cout<<'\n')
		for (int i = 0; i < n; i++)
			cout<<v[i][j]<<' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
/*

*/