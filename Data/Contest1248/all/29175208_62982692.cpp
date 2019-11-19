#include <iostream>
#include<algorithm>
#include <cmath>
#define int long long
using namespace std;
int n,a[1234567];
signed main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	int x = 1,sum = 0,sum2 = 0;
	for(int i = n;i >= x;i--)
	{
		sum += a[i];
		if(x != i)
			sum2 += a[x++];
	}
	cout << sum * sum + sum2 * sum2 << endl;
}