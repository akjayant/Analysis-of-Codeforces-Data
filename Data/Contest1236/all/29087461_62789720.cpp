#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL mod = 1e9 + 7;
LL ksm(LL x, LL y)
{
	if (y == 0) return 1;
	if (y == 1) return x;
	LL ans = ksm(x, y / 2);
	ans = (ans * ans) % mod;
	if (y & 1) ans = (ans * x) % mod;
	return ans;
}
int main()
{
	LL n, m;
	cin >> n >> m;
	cout << ksm(ksm(2, m) - 1, n);

}