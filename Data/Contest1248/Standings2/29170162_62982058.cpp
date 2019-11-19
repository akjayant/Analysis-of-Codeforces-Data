#include<bits/stdc++.h>
using namespace std;
int n,a[111111];
long long r1,r2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)r1+=a[i];
	for(int i=n/2+1;i<=n;i++)r2+=a[i];
	printf("%I64d",r1*r1+r2*r2);
}
