#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100000;
int n;
int a[N+5];
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int len=n/2,lena=0,lenb=0;
	for(int i=1;i<=len;i++) lena+=a[i];
	for(int i=len+1;i<=n;i++) lenb+=a[i];
	printf("%lld\n",lena*lena+lenb*lenb);
	return 0;
}