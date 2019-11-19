#include <bits/stdc++.h>
using namespace std;




int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int g1 = a / c;
		if(a % c != 0) g1++;
		int g2 = b / d;
		if(b % d != 0) g2++;
		if(g1 + g2 <= k) cout << g1 << " " << g2 << endl;
		else cout << -1 << endl;
	}
	
	return 0;
}