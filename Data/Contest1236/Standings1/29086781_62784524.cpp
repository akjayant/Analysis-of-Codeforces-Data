#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int t , a , b , c , n , x;

int main()
{
	int i , j;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		n = 0;
		x = min(b,c/2);
		n += x*3;
		b -= x;
		c -= x*2;
		x = min(a,b/2);
		n += x*3;
		a -= x;
		b -= x*2;
		cout << n << "\n";
	}
	return 0;
}
