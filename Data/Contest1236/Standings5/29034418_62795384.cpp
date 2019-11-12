#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
#define ll long long
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
int n;
int a[305][305];
int main()
{
	while (cin >> n)
	{
		int c = 1;
		for (int i = 1; i <= n; i++)
		{
			if (i & 1)
			{
				for (int j = 1; j <= n; j++)
					a[j][i] = c++;
			}
			else
			{
				for (int j = n; j >= 1; j--)
					a[j][i] = c++;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	
	}
}