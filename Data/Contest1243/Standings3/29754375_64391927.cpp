#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iterator>
#include <valarray>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <memory>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <tuple>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define m_p make_pair
#define fr first
#define sc second
#define endl '\n'
ll const N = 1000005, mod = 1000000007;
ll n, m, k, t, i, j, ans, kaskad[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (i = 2; i * i <= n; ++i)
	{
		if (n%i == 0)
		{
			while (n%i == 0)
			{
				n /= i;
			}
			if (n == 1)
			{
				cout << i << endl;
				return 0;
			}
			else
			{
				cout << 1 << endl;
				return 0;
			}
		}
	}
	cout << n << endl;
	return 0;
}