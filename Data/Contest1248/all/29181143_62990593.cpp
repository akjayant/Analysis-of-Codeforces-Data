#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n,a[1000050],sum,suma,sumb,l,r;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	sort(a+1,a+n+1,cmp);
	l=1,r=n;
	for(;l<r;l++,r--)suma+=a[l],sumb+=a[r];
	if(l==r)suma+=a[l];
	printf("%I64d",suma*suma+sumb*sumb);
	return 0;
}