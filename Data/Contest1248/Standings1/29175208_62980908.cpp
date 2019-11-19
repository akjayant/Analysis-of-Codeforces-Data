#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	int t;
	for(cin >> t;t--;)
	{
		int n,x;
		int a1,a2,b1,b2;
		a1 = a2 = b1 = b2 = 0;
		for(cin >> n;n-- && cin >> x;)
			if(x & 1)
				a1++;
			else
				a2++;
		for(cin >> n;n-- && cin >> x;)
			if(x & 1)
				b1++;
			else
				b2++;
		cout << a1 * b1 + a2 * b2 << endl;
	}
}