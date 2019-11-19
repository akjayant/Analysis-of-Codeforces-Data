

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--)
	{
		int lines;
		cin >> lines;
		int odd, even;
		odd = even = 0;
		while (lines--)
		{
			int x;
			cin >> x;
			if (x & 1)
				odd++;
			else
				even++;
		}
		int q;
		cin >> q;
		long long ans = 0;
		while (q--)
		{
			int x;
			cin >> x;
			if (x & 1)
				ans += (long long)odd;
			else
				ans += (long long)even;
		}
		cout << ans << "\n";
	}
	
}
