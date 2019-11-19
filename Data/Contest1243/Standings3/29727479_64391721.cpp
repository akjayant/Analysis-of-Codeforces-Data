#pragma GCC optimize("O3")

# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
 
#define LL long long
#define LD long double
//#define create(a,b,c,d) mp(a,mp(b,mp(c,d)))
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define opt ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define _sz(x) (int)x.size()
#define _all(x) x.begin(),x.end()
#define ld long double
#define lb(x, v) lower_bound(_all(x),v)
#define el '\n'
#define eb emplace_back

using namespace std;
const LL N = 150, INF = 1e9;

inline void solve()
{
	string s, t;
	LL n;
	cin >> n;
	LL cnt = 0, p = 0;
	for(LL i = 2; i*i <= n; i++)
	{
		if(n%i == 0)
		{
			if(cnt == 0)
			{
				while(n%i == 0) n/=i;
				p = i;
				cnt++;
			}
			else
			{
				cout << 1 << el;
				return;
			}
		}

	}
	if(cnt > 0 && n != 1)
	{
		cout << 1 << el;
		return;
	}
	if(cnt == 0)
		cout << n << el;
	else
		cout << p << el;
}

int main()
{
	LL test_count = 1;
	//cin >> test_count;
	for(LL test = 0; test < test_count; test++)
	{
		solve();
	}
}