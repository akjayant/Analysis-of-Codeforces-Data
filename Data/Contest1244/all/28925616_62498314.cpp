#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Dor(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
using namespace std;
const int N=1000007;
LL n,m,s;
int V[N];
int main() {
	scanf("%lld%lld",&n,&m),s=m;
	if(m<n*(n+1)>>1) {
		puts("-1");
		return 0;
	}
	m-=n*(n+1)>>1;
	For(i,1,n>>1) {
		int x=n-i-i+1;
		if(x<=m) m-=x;
		else {
			printf("%lld\n",s);
			For(j,1,n) printf("%d ",j); puts("");
			For(j,1,i-1) printf("%lld ",n-j+1),V[n-j+1]=1;
			printf("%lld ",i+m),V[i+m]=1;
			For(j,1,n)
			if(!V[j]) printf("%d ",j);
			return 0;
		}
	}
	printf("%lld\n",s-m);
	For(i,1,n) printf("%d ",i); puts("");
	Dor(i,n,1) printf("%d ",i); puts("");
	return 0;
}