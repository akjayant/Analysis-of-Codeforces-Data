#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define M 100005
int A[M],n;
int main(){
	int n;
	LL K;
	cin>>n>>K;
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+1+n);
	int L=1,R=n,lc=1,rc=1;
	while(L<R&&K){
		if(lc<rc){// lc
			//A[L]->A[L+1]
			LL cost=1LL*(A[L+1]-A[L])*lc;
			LL mi=min(cost,K);
			K-=mi;
			A[L]+=mi/lc;
			if(A[L]==A[L+1])L++,lc++;
		}else{
			LL cost=1LL*(A[R]-A[R-1])*rc;
			LL mi=min(cost,K);
			K-=mi;
			A[R]-=mi/lc;
			if(A[R]==A[R-1])R--,rc++;
		}
	}
	printf("%d\n",A[R]-A[L]);
	return 0;
}