#include <stdio.h>
//#include <conio.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;
typedef long long LL;
LL n, m, MOD = 1000000007;

LL sqr(LL x) {
	return x * x;
}

LL pow(LL a, LL b) {
	if (b == 0) return 1;
	else
		if (b % 2 == 0)
			return sqr(pow(a, b / 2)) % MOD;
		else
			return a * (sqr(pow(a, b / 2)) % MOD) % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	LL ans = pow(2LL, m);
	ans += MOD;
	ans -= 1;
	ans %= MOD;
	ans = pow(ans, n);
	cout << ans;



	//_getch();
	return 0;
}