#include<bits/stdc++.h>

using namespace std;

int T, a, b;

int gcd(int x, int y)
{
	return (y == 0) ? x : gcd(y, x % y);
}

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> a >> b;
		if(gcd(a, b) == 1) cout << "Finite" << endl;
		else cout << "Infinite" << endl;
	}
	return 0;
}