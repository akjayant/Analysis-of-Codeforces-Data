#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <time.h>
//#include <math.h>
#include <cmath>
#include <fstream>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <bitset>
#pragma comment(linker, "/STACK:36777216")
using namespace std;

#define flu fflush(stdout)
#define gg return 0
#define mp make_pair

long long mod = /*27449*//*998244353*/ 1e9 + 7 /*1e9 + 9*/;
long long inf = 1e9;
long double eps = 1e-7;
long double pi = acosl(-1);
ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
	string s;
	cin >> s;
	vector<long long> ans(s.size() + 1, 0);
	ans[0] = 1;
	ans[1] = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'm' || s[i] == 'w')
		{
			cout << 0;
			gg;
		}
	}
	for (int i = 1; i < s.size(); i++)
	{
		ans[i + 1] = ans[i] % mod;
		if (s[i] == 'u' && s[i - 1] == 'u')
		{
			ans[i + 1] = (ans[i + 1] + ans[i - 1]) % mod;
		}
		if (s[i] == 'n' && s[i - 1] == 'n')
		{
			ans[i + 1] = (ans[i + 1] + ans[i - 1]) % mod;
		}
	}
	cout << ans[s.size()];
	gg;
}