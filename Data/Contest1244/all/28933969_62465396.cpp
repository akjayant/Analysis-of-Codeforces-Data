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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = n;
		for (int i = 0; i < n; i++)
		{
			int cans = 0;
			if (s[i] == '1')
			{
				cans = max(2 * (i + 1), 2 * (n - i));
			}
			ans = max(ans, cans);
		}
		cout << ans << "\n";
	}
	gg;
}