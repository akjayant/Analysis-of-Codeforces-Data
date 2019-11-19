#include <bits/stdc++.h>
#define int long long

using namespace std;

int n=0,arr[200000];

signed main()
{
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
	}	
	sort(arr, arr+n);
	int a=0,b=0;
	for (int i=0; i<n/2; i++)
	{
		a+=arr[i];
	}
	for (int i=n/2; i<n; i++)
		b+=arr[i];
	cout << a*a+b*b;
	return 0;
}
