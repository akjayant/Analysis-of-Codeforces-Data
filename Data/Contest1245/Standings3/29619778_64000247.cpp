#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[12345];
int gcd(int x,int y)
{
	return y ? gcd(y,x % y) : x;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int x,y;
		cin >> x >> y;
		cout << ((gcd(x,y) == 1) ? "Finite" : "Infinite")<< endl;
	}
}