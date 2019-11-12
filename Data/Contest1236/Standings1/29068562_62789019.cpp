#include <algorithm>
#include  <iostream>
#include   <cstdlib>
#include   <cstring>
#include    <cstdio>
#include    <string>
#include    <vector>
#include    <bitset>
#include     <stack>
#include     <cmath>
#include     <deque>
#include     <queue>
#include      <list>
#include       <set>
#include       <map>
#define line printf("---------------------------\n")
#define mem(a, b) memset(a, b, sizeof(a))
#define pi acos(-1)
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int mod = 1e9+7;
const int maxn = 2e5+10;
const int minn = -1e8-10;

ll qpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {
			res = (a * res) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

int main() {
	ll n, m;
	cin >> n >> m;
	ll ans = qpow(2, m) - 1;
	ans = qpow(ans, n);
	cout << ans << endl;
}