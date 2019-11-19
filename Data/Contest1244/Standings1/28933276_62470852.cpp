#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int q = 0;
	cin >> q;

	int n = 0;
	string s;
	for (int k = 0; k < q; ++k)
	{
		cin >> n >> s;
		int ans = n;
		for (int i = 0; i < n; ++i)
			if (s[i] == '1')
				ans = max(ans, max((i + 1) * 2, (n - i) * 2));

		cout << ans << "\n";
	}

	return 0;
}