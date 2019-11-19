
#include <bits/stdc++.h>
using namespace std;

int a[100010];
int main()
{
	int n;
	long long sum = 0;
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}

	sort(a,a+n);
	long long sum2 = 0;
	for(int i=0; i<n/2; ++i)
		sum2 += a[i];
	long long sum1 = sum - sum2;

	cout << sum2*sum2 + sum1*sum1 << endl;

	return 0;
}