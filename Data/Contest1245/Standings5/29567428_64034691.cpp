#include <bits/stdc++.h>
using namespace std;
int col[1000000];
int main()
{
		int t,a,b;
		cin >> t;
		while (t--)
		{
		cin >> a >> b;
		if (a > b) swap(a,b);
		if (__gcd(a,b) == 1)
		{
				cout <<"finite"<<'\n';
		}
		else cout <<"infinite"<<'\n';
		}
}
