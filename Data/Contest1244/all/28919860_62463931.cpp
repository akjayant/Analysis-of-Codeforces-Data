#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <map>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <set>
#include <stack>


using namespace std;
using ll = long long;


#define SZ(a) a.size()
#define pb(a) push_back(a)
#define ALL(a) a.begin(), a.end()
#define mp(a,b) make_pair(a,b)


int main() {
	//ifstream cin("input.txt");
	int t;
	cin >> t;
	while (t--)
	{
		int cnt1=0, cnt2=0;
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		while (a > 0)
		{
			a -= c;
			cnt1++;
		}
		while (b > 0)
		{
			b -= d;
			cnt2++;
		}
		if (cnt1 + cnt2 <= k)
		{
			cout << cnt1 << " " << cnt2 << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}


	return 0;
}