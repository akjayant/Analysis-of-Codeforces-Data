#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 1e5 + 100;
LL a[MAXN];

int main()
{
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> a[i];
	}
	sort(a, a + n);
	int i;
	LL sum1 = 0, sum2 = 0;
	for (i = 0; i < n / 2; i++) {
		sum1 += a[i];
	}
	for ( ; i < n; i++) {
		sum2 += a[i];
	}
	cout << sum1 * sum1 + sum2 * sum2 << endl;
	
	return 0;
}