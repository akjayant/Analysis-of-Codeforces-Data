#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 10;
int n;
long long ans;
int a[MAXN];
long long sum1, sum2;
int main()
{
	int i;
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int div = n >> 1;
	for(i = n; i >= div + 1; i--)
	{
		sum1 += a[i];
	}
	for(i = 1; i <= div; i++)
	{
		sum2 += a[i];
	}
	cout << sum1 * sum1 + sum2 * sum2 << endl;
	return 0;
}
