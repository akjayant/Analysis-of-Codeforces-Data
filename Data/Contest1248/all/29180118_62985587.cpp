#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
using namespace std;
int n;
ll a[100004];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		
	 } 
	 sort(a+1,a+n+1);
	 if (n%2==0)
	 {
	 	ll ans=0;
	 	ll xx=0;
	 	ll yy=0;
	 	for (int i=1;i<=n;i++)
	 	{
	 		if (i<=n/2)
	 		{
	 			xx=xx+a[i];
			 }
			 else
			 {
			 	yy=yy+a[i];
			 }
		 }
		 cout<<xx*xx+yy*yy;
	 }
	 else
	 {
	 		ll ans=0;
	 	ll xx=0;
	 	ll yy=0;
	 	for (int i=1;i<=n;i++)
	 	{
	 		if (i<=n/2)
	 		{
	 			xx=xx+a[i];
			 }
			 else
			 {
			 	yy=yy+a[i];
			 }
		 }
		 cout<<xx*xx+yy*yy;
	 }
}

