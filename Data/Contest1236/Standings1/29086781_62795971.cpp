#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[310][310];

int main()
{
	int i , j;
	cin >> n;
	for (j = 1 ; j <= n ; j++)
		for (i = 1 ; i <= n ; i++)
			a[i][j] = (j%2 ? (j-1)*n+i : (j-1)*n+n-i+1);
	for (i = 1 ; i <= n ; i++)
		for (j = 1 ; j <= n ; j++)
			printf("%d%c",a[i][j],(j == n ? '\n' : ' '));
	return 0;
}
