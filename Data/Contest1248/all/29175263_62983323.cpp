#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
long long a[100001],x=0,y=0;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i*2<=n;i++)
		x+=a[i];
	for(int i=n/2+1;i<=n;i++)
		y+=a[i];
	x*=x,y*=y;
	x+=y;
	cout<<x<<endl;
	return 0;
}