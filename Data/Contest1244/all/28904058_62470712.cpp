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
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define m_p make_pair
#define fr first
#define sc second
#define endl '\n'
ll const N = 1e6 + 5, mod = 1e9 + 7;
ll n, m, k, i, j, kaskad[N], ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		string s;
		cin >> n >> s;
		ans = n;
		for (i = 0; i < n; ++i)
		{
			if (s[i] == '1')
			{
				ans = max(ans, max(2 * (i + 1), 2 * (n - i)));
			}
		}
		cout << ans << endl;

	}
	return 0;
}