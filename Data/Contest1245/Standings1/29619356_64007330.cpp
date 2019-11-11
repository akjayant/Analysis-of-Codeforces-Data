#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e6+10;
const LL mod = 1e9+7;

int n , a , b;

int main()
{
	int i , j;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		if (__gcd(a,b) == 1) cout << "Finite\n";
		else cout << "Infinite\n";
	}
	return 0;
}