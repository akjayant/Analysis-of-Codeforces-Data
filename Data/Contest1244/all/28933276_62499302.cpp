#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char getCh(int n, char ch)
{
	if (ch == 'W' && n % 2 == 0)
		return 'W';
	if (ch == 'B' && n % 2 == 1)
		return 'W';
	return 'B';
}

int main()
{
	int n = 0, k = 0;
	cin >> n >> k;

	string s;
	cin >> s;

	vector<int> p(n, n + 1);
	int counter = 0, last = -1;
	for (int j = 0; j < 2 * n; ++j)
	{
		int i = j % n;
		if (s[i] == s[(i + 1) % n] || s[i] == s[(i + n - 1) % n])
			p[i] = 0, counter++, last = i;
		else if (last != -1)
			p[i] = (i - last + n) % n;
	}

	last = -1;
	for (int j = 2*n - 2; j >= 0; --j)
	{
		int i = j % n;
		if (s[i] == s[(i + 1) % n] || s[i] == s[(i + n - 1) % n])
			last = i;
		else if (last != -1)
			p[i] = min(p[i], (last - i + n) % n);
	}

	string ans = s;
	for (int i = 0; i < n; ++i)
	{
		if (p[i] >= k || p[i] == n + 1)
			ans[i] = getCh(k, s[i]);
		else
			ans[i] = getCh(p[i], s[i]);
	}

	cout << ans << endl;

	return 0;
}