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
bool good[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	cin >> n >> k;
	string s;
	cin >> s;
	int skizb = -1;
	for (i = 0; i < n; ++i)
	{
		if (s[i] == s[(i + 1) % n] || s[i] == s[(i - 1 + n) % n])
		{
			good[i] = true;
			skizb = i;
		}
	}
	if (skizb == -1)
	{
		if (k % 2 == 0)
			cout << s << endl;
		else
		{
			for (i = 0; i < n; ++i)
				cout << char('W' + 'B' - s[i] );
			cout << endl;
		}
		return 0;
	}
	s += s;
	ll count = 0;
	ll skzb = skizb;
	for (i = skzb; i <= n + skzb; ++i)
	{
		if (!good[i%n])
			count++;
		else
		{
			m = min((count + 1) / 2, k);
			for (j = skizb + 1; j <= skizb + m; ++j)
			{
				s[j] = s[skizb];
				good[j%n] = true;
			}
			for (j = i - 1; j >= i - m; --j)
			{
				s[j] = s[i];
				good[j%n] = true;
			}
			skizb = i;
			count = 0;
		}
	}
	for (i = n; i < n + skzb; ++i)
	{
		if (good[i%n])
			cout << s[i];
		else
		{
			if (k % 2 == 0)
				cout << s[i];
			else
			{
				cout << char('W' + 'B' - s[i]);
			}
		}
	}
	for (i = skzb; i < n; ++i)
	{
		if (good[i%n])
			cout << s[i];
		else
		{
			if (k % 2 == 0)
				cout << s[i];
			else
			{
				cout << char('W' + 'B' - s[i]);
			}
		}
	}
	return 0;
}