#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;

const int maxx = 1e7 + 5;
const double PI = acos(-1.0);
const long long inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

ll n, m, N, M;

ll ppow(ll x, ll y){
	ll res = 1;
	while(y){
		if(y & 1) res = res * x % mod;
		y >>= 1;
		x = x * x % mod;
	}
	return res;
}

int main(){
	int i, j, k;
	scanf("%d %d", &n, &m);
	N = ppow(2, m);
	M = ppow(N - 1, n);
	printf("%lld\n", M);
	return 0;
}