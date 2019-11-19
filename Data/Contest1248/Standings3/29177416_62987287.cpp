#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
ll a[100005];

int main()
{
	int n;
	ll sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		sum+=a[i];
	}	
	sort(a+1,a+n+1);
	ll tt=0;
	for(int i=1;i<=n/2;i++)
	{
		tt+=a[i];
	}
	ll ans=tt*tt+(sum-tt)*(sum-tt);
	cout<<ans<<endl;
	return 0;
}