#include<bits/stdc++.h>
using namespace std;
const int mmod = 1e9 + 7;
void ddo()
{
	long long n, m;
	long long x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		if(x & 1)x1 ++;
		else y1 ++;
	}
	cin >> m;
	for(int i = 1; i <= m; i ++)
	{
		int x;
		cin >> x;
		if(x & 1) x2 ++;
		else y2 ++;
	}
	cout << x1 * x2 + y1 * y2<<"\n";
	return; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		ddo();
	}
	return 0;
}