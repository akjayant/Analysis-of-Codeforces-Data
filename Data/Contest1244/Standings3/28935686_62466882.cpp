#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , a , b , c , d , k; 

void work()
{
	for (int i = 0 ; i <= k ; i++)
		for (int j = 0 ; j <= k-i ; j++)
			if (c*i >= a && d*j >= b)
			{
				cout << i << " " << j << "\n";
				return;
			}
	cout << "-1\n";
}

int main()
{
	int i , j;
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c >> d >> k;
		work();
	}
	return 0;
}
