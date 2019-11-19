#include<bits/stdc++.h>
#define M 100005
using namespace std;
int n,A[M];
long long k;
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=1; i<=n; i++)scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	int l=1,r=n,L=A[1],R=A[n];
	long long down=1,up=1;
	while(k&&R>L) {
		if(down<up) {
			if(k>=1LL*down*(A[l+1]-A[l])) {
				k-=1LL*down*(A[l+1]-A[l]);
				l++;
				L=A[l];
				down++;
			} else {
				L+=k/down;
				break;
			}
		} else {
			if(k>=1LL*up*(A[r]-A[r-1])) {
				k-=1LL*up*(A[r]-A[r-1]);
				r--;
				R=A[r];
				up++;
			} else {
				R-=k/up;
				break;
			}
		}
	}
//	printf("%d %d\n",L,R);
	printf("%d\n",R-L);
	return 0;
}