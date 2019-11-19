#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int n;
	long long x=0,y=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);	
	sort(a,a+n);
	for(int i=0;i<n/2;i++)x+=a[i];
	for(int i=n/2;i<n;i++)y+=a[i];
	printf("%I64d\n",x*x+y*y);
}