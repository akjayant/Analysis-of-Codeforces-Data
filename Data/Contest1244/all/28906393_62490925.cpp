#include<bits/stdc++.h>

using namespace std;

main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for(long long i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	long long l1 = 0, l2 = 1, r1 = n - 1, r2 = n - 2;
	long long mn = a.back() - a.front();
	long long mnc = a.front();
	long long mxc = a.back();
	while(l1 < r1)
	{
		if(k == 0)
			break;
		if(l1 + 1 <= n - r1)
		{
			long long res = a[l2] - a[l1];
			if(k >= res * (l1 + 1))
			{
				k -= res * (l1 + 1);
				mnc += res;
				l1++;
				l2++;
			}
			else
			{
				long long g = k / (l1 + 1);
				mnc += g;
				k -= g * (l1 + 1);
				if(k > 0)
				{
					g = k / (n - r1);
					mxc -= g;
					break;
				}
				else
					break;
			}
		}
		else
		{
			long long res = a[r1] - a[r2];
			if(k >= res * (n - r1))
			{
				k -= res * (n - r1);
				mxc -= res;
				r1--;
				r2--;
			}
			else
			{
				long long g = k / (n - r1);
				mxc -= g;
				k -= g * (n - r1);
				if(k > 0)
				{
					g = k / (l1);
					mnc += g;
					break;
				}
				else
					break;
			}
		}
	}
	cout << mxc - mnc;
}