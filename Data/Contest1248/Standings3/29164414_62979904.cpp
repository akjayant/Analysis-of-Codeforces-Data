

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
	int nn = n;
	priority_queue<int> all;
	while (n--)
	{
		int x;
		cin >> x;
		all.push(x);
	}

	int x = 0;
	int y = 0;
	int got = 0;
	while (all.size())
	{
		int top = all.top();
		all.pop();
		if (got * 2 < nn)
			x += top;
		else
			y += top;
		got++;
	}
	cout << (long long)x * x + (long long)y * y << "\n";
}
