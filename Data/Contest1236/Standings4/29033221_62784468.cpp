#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b,c;
		cin >> a >> b >> c;
		int f = c/2;
		int ff = min(b,f);
		int ans = ff;
		b -= ff;
		int fff = b/2;
		ans += min(a,fff);
		cout << 3*ans << endl;
	}
}