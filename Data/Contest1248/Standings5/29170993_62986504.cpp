#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

long long ans;
int t;
int n, m;

int main()
{
//	scanf("%d", &t);
	cin >> t;
	while(t--)
	{
//		scanf("%d", &n);
		long long t1 = 0, t2 = 0;
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			long long x;
			cin >> x;
			if(x & 1)
			{
				t1++;
			}
			else
				t2++;
		}
		cin >> m;
		for(int i = 1; i <= m; i++)
		{
			long long x;
			cin >> x;
			if(x & 1)
			{
				ans += t1;
			}
			else
			{
				ans += t2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
