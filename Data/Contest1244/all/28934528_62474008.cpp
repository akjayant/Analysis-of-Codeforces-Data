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
int arr[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
#endif
	int n; ll k;
	cin >> n >> k;
	map<int, int> freq;
	for (int i = 0; i < n; i++)
	{
		int val; scanf("%d", &val);
		freq[val]++;
	}
	while (k && freq.size() > 1)
	{
		auto it_l = freq.begin();
		auto it_r = --freq.end();
		if (it_r->second >= it_l->second)
		{
			auto nxt = ++freq.begin();

			ppi v = *it_l; 
			freq.erase(it_l);

			int dis = (nxt->first - v.first);

			if (1LL * dis * v.second <= k)
			{
				k -= 1LL * dis * v.second;
				nxt->second += v.second;
			}
			else
			{
				int go = k / v.second + v.first;
				freq[go]++;
				k = 0;
			}
		}
		else
		{
			auto nxt = ----freq.end();

			ppi v = *it_r;
			freq.erase(it_r);

			int dis = (v.first - nxt->first);

			if (1LL * dis * v.second <= k)
			{
				k -= 1LL * dis * v.second;
				nxt->second += v.second;
			}
			else
			{
				int go = -k / v.second + v.first;
				freq[go]++;
				k = 0;
			}
		}
	}
	cout << (--freq.end())->first - freq.begin()->first;
}