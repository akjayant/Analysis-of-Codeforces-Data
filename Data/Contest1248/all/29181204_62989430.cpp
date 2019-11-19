#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000001];
int main()
{
	cin>>n;
	long long x=0,y=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		if(i<=n/2) x+=a[i];
		else y+=a[i];
	}
	cout<<x*x+y*y;
	return 0;
}
