#include<bits/stdc++.h>
using namespace std;
long long n,t,m; 
long long a[1000001],b[1000001],s1,s2,s3,s4;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	s1=0;
	s2=0;
	for(int i=1;i<=n/2;i++)
	{
		s1+=a[i];
	}
	for(int i=n/2+1;i<=n;i++)
	{
		s2+=a[i];
	}
	cout<<s1*s1+s2*s2<<endl;
}
