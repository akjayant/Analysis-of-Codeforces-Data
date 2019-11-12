#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int T,n;
int a[maxn];

int main()
{
	cin >> T;
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d",a+i);
		}
		sort(a,a+n);
		int ans = 1;
		for(int i = 0; i < n; i++)
		{
			if(n - i <= a[i])
			{
				ans = min(a[i],n - i);
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

