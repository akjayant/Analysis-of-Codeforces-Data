#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	long long int sum=0,sum2=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	for (int i = 0; i < n/2; ++i)
	{
		sum2+=a[i];
		sum-=a[i];
	}
	cout<<sum*sum+sum2*sum2<<endl;
}