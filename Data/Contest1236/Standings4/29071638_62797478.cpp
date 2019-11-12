#include<bits/stdc++.h>
using namespace std;
int a[310][310];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int i = 1, j = 1, fz = 1;
	while(i <= n && j <= n)
	{
		a[i][j] = fz;
		if(j & 1)
		{
			i ++;
		}
		else
		{
			i --;
		}
		if(i == 0)
		{
			j ++;
			i = 1;
		}
		if(i == n + 1)
		{
			j ++;
			i = n;
		}
		fz ++;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j < n; j ++)
		{
			cout << a[i][j]<<" ";
		}
		cout << a[i][n]<<"\n";
	}
	return 0;
}