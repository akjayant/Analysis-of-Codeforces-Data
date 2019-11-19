#include <iostream>
using namespace std;
long long cd,m,n,d[2],a[100001],b;
int main()
{
				long long t;
				cin >> t;
				while (t--)
				{
		cin >> n;
		long long kq = 0;
		for (long long i = 1 ; i <= n ; i++)
		{
				cin >> a[i];
				if (a[i] <= 0)
				{
						a[i] = 0 - a[i];
				}
				d[a[i]%2]++;
		}
		cin >> m;
		for (long long i = 1 ; i <= m ; i++)
		{
				cin >> b;
				if (b < 0)
				{
						b = 0 - b;
				}
				kq += d[b % 2];
		}
		cout << kq<<'\n';
		d[0] = d[1] = 0;
		}
}