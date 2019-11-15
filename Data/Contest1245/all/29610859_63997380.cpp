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


int n, m;
int A[MAXN];
int main() {
	scanf("%d", &n);
	
	while(n--) {
		int a, b;
		scanf("%d %d", &a, &b);

		if(__gcd(a, b)==1)
			puts("Finite");
		else
			puts("Infinite");
	}
	return 0;
}