#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,A[N],l,r,now;
long long m;
int main() {
	scanf("%d %lld",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	l=1,r=n;
	while(l<r) {
		now=A[l];
		while(A[l+1]==now)++l;
		now=A[r];
		while(A[r-1]==now)--r;
		if(l>=r)break;
		if(l<n-r+1) {
			if(m>=1ll*l*(A[l+1]-A[l])) {
				m-=1ll*l*(A[l+1]-A[l]);
				++l;
			} else break;
		} else {
//			printf("%d %d %lld\n",A[r]-A[r-1],n-r+1,m);
			if(m>=1ll*(n-r+1)*(A[r]-A[r-1])) {
				m-=1ll*(n-r+1)*(A[r]-A[r-1]);
				--r;
			} else break;
		}
	}
	if(l>=r)puts("0");
	else printf("%lld\n",A[r]-A[l]-m/min(l,n-r+1));
	return 0;
}
