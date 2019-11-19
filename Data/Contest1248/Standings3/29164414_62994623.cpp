

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define int long long
const int MOD = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> sum;
	sum.push_back(2);
	sum.push_back(2);
	for (int i = 2; i < 1e5 + 12; i++)
	{
		sum.push_back(sum[i - 2] + sum[i - 1]);
		sum[i] %= MOD;
	}
	int curr = 2;
	n--; m--;
	int idx = 0;
	while (n--)
	{
		curr += sum[idx];
		idx++;
		curr %= MOD;
	}
	idx = 0;
	while (m--)
	{
		curr += sum[idx];
		idx++;
		curr %= MOD;
	}
	cout << curr << "\n";
}
