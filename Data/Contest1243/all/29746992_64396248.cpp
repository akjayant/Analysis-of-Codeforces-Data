#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<map>
#include<unordered_map>
#ifdef LOCAL
#include"file.h"
#endif

#define y1 zyy_orz
#define hash sto_zyy

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL>pLL;
typedef pair<int, int>pii;
const double eps = 1e-10;
const double Pi = 3.1415926535897932;
const int dir[4][2] = { -1,0,0,-1,1,0,0,1 };
//const int dir[8][2] = { -2,-1,-2,1,2,-1,2,1,-1,2,-1,-2,1,2,1,-2 };







const int maxn = 2e6 + 5;
int prime[maxn]; int pn = 0;
bool is_prime[maxn];


vector<LL>A;
int main() {
#ifdef LOCAL
	fileopen();
#endif

	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;

	LL n = maxn - 3;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime[++pn] = i;
		}
		for (int j = 1; j <= pn && i*prime[j] <= n; j++) {
			is_prime[i*prime[j]] = false;
			if (i%prime[j] == 0) {
				break;
			}
		}
	}
	scanf("%lld", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i <= pn; i++)if (n%prime[i] == 0) {
		A.push_back(prime[i]);
		while (n%prime[i] == 0)n /= prime[i];
	}
	if (n != 1)A.push_back(n);
	if (A.size() >= 2)printf("1\n");
	else printf("%lld\n", A[0]);

#ifdef LOCAL
	fileclose();
#endif
	return 0;
}
