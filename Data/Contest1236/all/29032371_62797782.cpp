#include <bits/stdc++.h>
using namespace std;
int a[305][305];

int main()
{
	int n;
	cin >> n;
	
	int x = 1;
	
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		for(int j = 0; j < n; j++)
		{
			a[j][i] = x;
			x++;
		}
		else
		for(int j = n - 1; j >= 0; j--)
		{
			a[j][i] = x;
			x++;
		}
	}
	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}