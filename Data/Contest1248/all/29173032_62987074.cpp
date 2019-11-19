//ZJ_MRZ's Code
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#define N 100010
using namespace std;
long long a[N];
int main() {
	long long n,x=0,y=0;
	bool bo=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) 
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r) {
		x+=a[l];
		y+=a[r];
		l++;
		r--;
	}
	if(l==r)
		y+=a[l];
	long long ans=x*x+y*y;
	printf("%lld\n",ans);
	return 0;
}