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
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	string t;
	cin >> t;
	vector <int> let(26, 0);
	for (int i = 0; i < n; i++)
	{
		let[s[i] - 'a']++;
		let[t[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (let[i] % 2 != 0)
		{
			printf("No\n");
			return;
		}
	}
	int cntSolved = 0;
	int curIndS = 0;
	vector<pair <int, int>> ans;
	vector <bool> used(n, false);
	while (cntSolved != n)
	{
		if (s[curIndS] == t[curIndS])
		{
			cntSolved++;
			used[curIndS] = true;
			for (int i = 0; i < n; i++)
			{
				if (s[i] != t[i])
				{
					curIndS = i;
					break;
				}
			}
			continue;
		}
		int nxtIndS = -1;
		for (int i = 0; i < n; i++)
		{
			if (i != curIndS && !used[i] && s[i] == s[curIndS])
			{
				nxtIndS = i;
				break;
			}
		}
		if (nxtIndS != -1)
		{
			ans.push_back({ nxtIndS, curIndS });
			swap(s[nxtIndS], t[curIndS]);
			used[curIndS] = true;
			curIndS = nxtIndS;
			continue;
		}
		int nxtIndSame = -1;
		for (int i = 0; i < n; i++)
		{
			if (i != curIndS && !used[i] && t[i] == s[curIndS])
			{
				nxtIndSame = i;
				break;
			}
		}
		int nxtIndT = -1;
		for (int i = 0; i < n; i++)
		{
			if (i != curIndS && !used[i])
			{
				nxtIndT = i;
				break;
			}
		}
		ans.push_back({ nxtIndT, nxtIndSame });
		ans.push_back({ nxtIndT, curIndS });
		used[curIndS] = true;
		swap(s[nxtIndT], t[nxtIndSame]);
		swap(s[nxtIndT], t[curIndS]);
		curIndS = nxtIndT;
	}
	printf("Yes\n");
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d %d\n", x.first + 1, x.second + 1);
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
	//solve();
	multitest();
}