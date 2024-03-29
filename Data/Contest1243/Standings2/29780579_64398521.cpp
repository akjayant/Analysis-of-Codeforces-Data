#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//#include <unordered_map>
#include <set>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <bitset>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
using namespace std;


//inline int FastI() {
//	char c = ' '; int a = 0;
//	while (!isdigit(c)) c = getchar_unlocked();
//	while (isdigit(c)) {
//		a *= 10;
//		a += c - '0';
//		c = getchar_unlocked();
//	}
//	return a;
//}
//
//inline void FastO(int val) {
//	bool c = 0;
//	for (int i = 1000000000; i >= 1; i /= 10) {
//		if (val / i) {
//			c = 1;
//			fputc_unlocked(val / i + '0', stdout);
//			val %= i;
//		}
//		else if (c) fputc_unlocked('0', stdout);
//	}
//	if (!c) fputc_unlocked('0', stdout);
//}
//
//inline void FastO(long long val) {
//	bool c = 0;
//	for (long long i = 1000000000000000000; i >= 1; i /= 10) {
//		if (val / i) {
//			c = 1;
//			fputc_unlocked(val / i + '0', stdout);
//			val %= i;
//		}
//		else if (c) fputc_unlocked('0', stdout);
//	}
//	if (!c) fputc_unlocked('0', stdout);
//}


const int MAX_N = 1e5 + 10;
const int MAX_M = 1e5 + 10;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;


void solve()
{
	long long n;
	scanf("%lld", &n);
	if (n == 1)
	{
		printf("1");
		return;
	}
	long long cn = n;
	int cnt = 0;
	long long div = -1;
	for (long long i = 2; i * i <= cn; i++)
	{
		if (n % i == 0)
		{
			div = i;
			while (n % i == 0)
				n /= i;
			cnt++;
		}
	}
	if (n != 1)
	{
		cnt++;
		div = n;
	}
	if (cnt > 1)
		printf("1");
	else if (cn == div)
		printf("%lld", cn);
	else
		printf("%lld", div);
}


void multitest()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	//multitest();
}