#include <bits/stdc++.h>

using namespace std;

#define int long long

int n,k;
vector<int> a;
map<int,int> cnt;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
		cnt[x]++;
	}
	sort(a.begin(),a.end());
	int sz = (unique(a.begin(),a.end()) - a.begin());
	int l = 0;
	int r =	sz - 1;
	int res = a[r] - a[l];
	while(l != r)
	{
		int dl = cnt[a[l]];
		int dr = cnt[a[r]];
		if (dl > k && dr > k)
			break;
		if (dl < dr)
		{
			int f = (a[l] + k/dl);
			if (f < a[l+1])
			{
				res -= (f - a[l]);
				break;
			}
			k -= dl*(a[l+1] - a[l]);
			res -= (a[l+1] - a[l]);
			cnt[a[l]] -= dl;
			cnt[a[l+1]] += dl;
			l++;
		}
		else
		{
			int f = (a[r] - k/dr);
			if (f > a[r-1])
			{
				res -= (a[r] - f);
				break;
			}
			k -= dr*(a[r] - a[r-1]);
			res -= (a[r] - a[r-1]);
			cnt[a[r]] -= dr;
			cnt[a[r-1]] += dr;
			r--;
		}
	}
	cout << res;
}
