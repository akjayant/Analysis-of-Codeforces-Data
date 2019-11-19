#include<bits/stdc++.h>
#define int long long
const int N = 1e5 + 3;
int a[N],n;

signed main()
{
	std::cin >> n;
	for(int i = 1;i <= n;i++) std::cin >> a[i];
	std::sort(a + 1,a + 1 + n);
	int m = floor(1. * n / 2),tmp0 = 0,tmp1 = 0;
	for(int i = 1;i <= m;i++) tmp0 += a[i];
	for(int i = m + 1;i <= n;i++)tmp1 += a[i];

	std::cout << tmp0 * tmp0 + tmp1 * tmp1;

	exit(0);
}
