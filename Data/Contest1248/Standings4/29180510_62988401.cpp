#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int p[maxn], q[maxn];
signed main()
{
	int n,res=0,res1=0;
	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> p[i];
	sort(p + 1, p + 1 + n);
	for (int i = n / 2+1; i <= n; i++) 	res += p[i];
	for (int i = 1; i <= n / 2; i++)	res1 += p[i];
	cout << res * res + res1 * res1 << endl;
	return 0;
}