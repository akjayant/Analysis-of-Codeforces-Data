#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll flag=0;
int main()
{
	ll test,a,b,c,d,k;
	cin >> test;
	while(test--)
	{
		cin >> a >> b >> c >> d >> k;
		ll x=a/c;
		if(a%c>0)
			x++;
		ll y=b/d;
		if(b%d>0)
			y++;
		if((x+y)<=k)
			cout << x << " " << y << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}