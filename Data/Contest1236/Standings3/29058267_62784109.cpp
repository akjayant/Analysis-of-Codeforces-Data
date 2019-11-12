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
		int x=min(b,c/2);
		b-=x; c-=2*x;
		int ans=3*x;
		x=min(a,b/2);
		ans+=3*x;
		cout << ans << endl;
	}
}