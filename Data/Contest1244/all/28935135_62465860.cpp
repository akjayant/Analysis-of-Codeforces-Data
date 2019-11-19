#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
 
const int N = 33333;
const int M = 666;
const ll md = 1e9 + 7;
 
int n, m, k, q;
int ans;
int x, y;

int f(int a, int b)
{
	return (b - 1) / a + 1;
}

int main()
{
	ios::sync_with_stdio(false); cout<<setprecision(20);
 
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
		if (f(x, n) + f(y, m) > k)
		{
			puts("-1");
		}
		else
		{
			printf("%d %d\n", f(x, n), f(y, m));
		}
	}
	
	return 0;
}