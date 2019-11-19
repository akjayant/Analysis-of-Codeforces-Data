#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 2;
int a[N];
signed main()
{
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	int ans = a[n] - a[1];
	int l = 1,r = 1;
	while(l + r <= n)
	{
		if(l < r)
		{
			int dd = a[l + 1] - a[l],delta = dd * l;
			if(k >= delta)
				k -= delta,l++,ans -= dd;
			else
			{
				ans -= k / l;
				break;
			}
		}
		else
		{
			int R = n - r + 1;
			int dd = a[R] - a[R - 1],delta = dd * r;
			if(k >= delta)
				k -= delta,r++,ans -= dd;
			else
			{
				ans -= k / r;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}