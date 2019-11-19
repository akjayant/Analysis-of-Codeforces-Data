#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
int A[maxn];
typedef long long ll;
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	int x=0,y=0;
	int l=1,r=n;
	int t=n/2;
	for(int i=1;i<=t;i++)
		x+=A[i],y+=A[n-i+1];
	if(n&1)
		y+=A[t+1];
	printf("%lld\n",1ll*x*x+1ll*y*y);
return 0;
}