
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		scanf("%d",&n);
		int sumj(0),sumo(0);
		long long ans(0);
		int x;
		while(n--)
		{
			scanf("%d",&x);
			if(x % 2 == 0)
				sumo++;
			else
				sumj++;
		}

		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&x);
			if(x % 2 == 0)
				ans += sumo;
			else
				ans += sumj;
		}

		cout << ans << endl;
	}

	return 0;
}