#include <bits/stdc++.h>
using namespace std;

#define IOS                               \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);
#define int long long int
#define endl "\n"
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()

const int N = 1000009;
const int mod = 1000000007;

int t;
int a, b, c;

// bool check(int itne)
// {
// 	for(int i=0;<=a;i++)
// 	{
// 		int wo =
// 	}
// }

void pre()
{
}

int32_t main()
{
	IOS;
	pre();
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		// int l = 0;
		// int r = (a + b + c);
		// while (l < r)
		// {
		// 	int mid = (l + r + 1) / 2;
		// 	if (check(mid))
		// 	{
		// 		l = mid;
		// 	}
		// 	else
		// 	{
		// 		r = mid - 1;
		// 	}
		// }
		// cout << l << endl;
		int ans = 0;
		for (int i = 0; i <= a; i++)
		{
			for (int j = 0; j <= c; j += 2)
			{
				if ((2 * i + j / 2) <= b)
				{
					ans = max(ans, 3 * i + (3 * j / 2));
					// cout << ans << " " << i << " " << j << endl;
				}
			}
		}
		cout << ans << endl;
	}
}