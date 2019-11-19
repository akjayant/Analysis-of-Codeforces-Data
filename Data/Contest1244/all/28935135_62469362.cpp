#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
 
const int N = 111111;
const int M = 666;
const ll md = 1e9 + 7;
 
int n, m, k, q;
int ans;
char s[N];

int main()
{
	ios::sync_with_stdio(false); cout<<setprecision(20);
 
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%s", &n, s);
		k = -1;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
			{
				k = max(k, max(i + 1, n - i));
			}
		}
		if (k == -1)
		{
			ans = n;
		}
		else
		{
			ans = 2 * k;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}