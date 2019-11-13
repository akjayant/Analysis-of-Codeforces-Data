#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const long long LINF = 1e18 + 1;
typedef long long ll;
typedef pair<int, int> P;

ll mul(ll a, int b)
{
	ll ret = 1;
	while (b)
	{
		if (b % 2)
			ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return ret;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	ll ans = mul(2, M)-1;
	ans = mul(ans, N);
	printf("%d\n", ans);
	return 0;
}