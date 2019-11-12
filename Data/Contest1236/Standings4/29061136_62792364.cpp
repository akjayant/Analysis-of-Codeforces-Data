#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;
#define fio ios::sync_with_stdio(false); cin.tie(NULL);

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INT_INF = 1e9;
const ll LL_INF = 1e18;
const int MAXN = 500010;

typedef struct GE{
	int to;
	ll w;
}GE;

const ll mod = 1e9+7;

ll my_pow(ll x, ll n){
	ll ret = 1;
	while(n){
		if(n&1) ret *= x;
		x*=x;
		x%=mod;
		ret%=mod;
		n>>=1;
	}
	return ret;
}

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll all = my_pow(2ll, m);
	ll ans = my_pow(all-1, n);
	printf("%lld", ans);
	
	return 0;
}