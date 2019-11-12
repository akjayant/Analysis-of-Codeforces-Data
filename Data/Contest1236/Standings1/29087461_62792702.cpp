#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL mod = 1e9 + 7;

int a[305][305];
int main()
{
	int n;
	cin >> n;
	int k = n * n+1;
	int i = 1, j = 1;
	int f = 1;
	while (k--)
	{
		a[i][j] = k;
		i+=f;
		if (i > n)
		{
			i = n;
			j = j + 1;
			f = -1;
		}
		else if (i < 1)
		{
			i = 1;
			j = j + 1;
			f = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}