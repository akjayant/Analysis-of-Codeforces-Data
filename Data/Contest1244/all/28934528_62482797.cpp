#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <string>
#include <memory.h>
#include <bitset>
#include <stack>
#include <assert.h>
using namespace std;
#define ll  long long
#define ld long double
#define ppi pair<int, int>
#define mp make_pair	
const int N = 2e5 + 111 , NS = 1e6 + 11;
ll n, p, w, d;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n; string x;
		cin >> n >> x;
		int mx = 0;
		for (int i = 0; i < n; i++)
		{
			int add = i + 1;
			mx = max(mx, add);
			if (x[i] == '1')
				mx = max(mx, add + 1 + max(add - 1, n - add));
		}
		for (int i = n - 1; i >= 0; i--)
		{
			int add = n - i;
			mx = max(mx, add);
			if (x[i] == '1')
				mx = max(mx, add + 1 + max(add - 1, n - add ));
		}
		cout << mx << endl;
	}
}