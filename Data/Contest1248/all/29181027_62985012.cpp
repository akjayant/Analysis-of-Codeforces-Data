#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,a[N];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int x=0,y=0;
	for(int i=1;i<=(n/2);i++) x+=a[i];
	for(int i=(n/2)+1;i<=n;i++) y+=a[i];

	printf("%lld",x*x+y*y);
}