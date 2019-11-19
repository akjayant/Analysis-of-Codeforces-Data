#include <bits/stdc++.h>
using namespace std;
char c[123456];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cin >> (c + 1);
		int x = 0,y = 0,cnt = 0;
		for(int i = 1;i <= n;i++)
			if(c[i] == '1')
				x = i,cnt++;
		for(int i = n;i >= 1;i--)
			if(c[i] == '1')
				y = i;
		int ans = n + cnt;
		if(x)
			ans = max(ans,2 * x);
		if(y)
			ans = max(ans,2 * (n - y + 1));
		cout << ans << endl;
	}
}