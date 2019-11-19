#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <ctime>

using namespace std;

long long t, n, m, a[100010], cnt2[2], ans, ret;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i * 2 <= n; i++)
		ans += a[i];
	for(int i= n / 2 + 1; i <= n; i++)
		ret += a[i];
	ans *= ans;
	ret *= ret;
	ans += ret;
	cout << ans << endl;
	return 0;
}