#include <bits/stdc++.h>
using namespace std;



int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int res = min(b, c / 2) * 3;
		b -= min(b, c / 2);
		res += min(a, b / 2) * 3;
		cout << res << endl;
	}
	
	
	
	return 0;
}