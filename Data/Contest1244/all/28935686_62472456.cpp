#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n , b1 , b2; 
string a;

int main()
{
	int i , j;
	cin >> T;
	while (T--)
	{
		scanf("%d",&n);
		cin >> a;
		b1 = -1;
		for (i = 0 ; i < n ; i++)
			if (a[i] == '1')
			{
				if (b1 == -1) b1 = i+1;
				b2 = i+1;
			}
		if (b1 == -1) cout << n << "\n";
		else cout << n*2-min(n-b2,b1-1)*2 << "\n";
	}
	return 0;
}
