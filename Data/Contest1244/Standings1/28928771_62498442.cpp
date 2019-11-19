#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, k, arr[1000010];
vector<int> p, q, sq;
bool occur[1000010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	ll t = k;
	if (k < n * (n + 1) / 2)
	{
		cout << -1 << endl;
		return 0;
	}
	k -= n * (n + 1) / 2;
	int cur = n, cnt = 1;
	arr[n] = n;
	for (int i = n - 1; i >= 1; i--)
	{
		if (cur - i > k)
		{
			arr[i] = k + i;
			for (int j = 1; j < i; j++)
				arr[j] = j;
			k = 0;
			break;
		}
		arr[i] = cur, k -= cur - i;
		if (cnt == 1)
		{
			cur--;
			cnt = 0;
		}
		else cnt++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == arr[i - 1]) q.push_back(arr[i]);
		else p.push_back(arr[i]);
	}
	for (int i = 0; i < p.size(); i++) occur[p[i]] = 1;
	for (int i = 1; i <= n; i++)
		if (!occur[i])
			p.push_back(i);
	cout << t - k << endl;
	for (int i = 0; i < p.size(); i++)
		cout << p[i] << ' ';
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << i << ' ';
	cout << endl;
	return 0;
}
