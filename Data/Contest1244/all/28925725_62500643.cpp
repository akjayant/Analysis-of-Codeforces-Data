#include<cstdio>
#include<algorithm>
#define M 100005
using namespace std;
int A[M];
int n;
long long K;
long long Pre[M],Suf[M];
bool check(int mid){
	int p=1;
	for(int i=1;i<=n;i++){
		while(p<n&&A[p]-A[i]<mid)p++;
		p=max(p,i);
		long long res=1ll*A[i]*i-Pre[i]+Suf[p]-1ll*A[p]*(n-p+1);
		long long cost=0;
		if(A[p]-A[i]>mid)cost=1ll*(A[p]-A[i]-mid)*(n-p+1);
		if(A[p]-A[i]>mid&&A[p]-A[i]-mid<=A[i+1]-A[i]&&i!=n)cost=min(cost,1ll*(A[p]-A[i]-mid)*i);
		if(res+cost<=1ll*K)return true;
	}
	return false;
}
long long Solve(){
	int L=1,R=n;
	long long res=0;
	while(L<R){
		int cost_L=L,cost_R=n-R+1;
		if(cost_L<=cost_R){
			if(1ll*cost_L*(A[L+1]-A[L])+res<=K){
				res+=1ll*cost_L*(A[L+1]-A[L]);
				L++;
			}else{
				return A[R]-A[L]-1ll*(K-res)/cost_L;
			}
		}else{
			if(1ll*cost_R*(A[R]-A[R-1])+res<=K){
				res+=1ll*cost_R*(A[R]-A[R-1]);
				R--;
			}else{
				return A[R]-A[L]-1ll*(K-res)/cost_R;
			}
		}
	}
	return A[R]-A[L];
}
int main(){
	scanf("%d%lld",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++)Pre[i]=Pre[i-1]+A[i];
	for(int i=n;i>=1;i--)Suf[i]=Suf[i+1]+A[i];
	int L=0,R=A[n]-A[1],ans=A[n]-A[1];
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;
			R=mid-1;
		}else L=mid+1;
	}
	//printf("%lld\n",Solve());
	printf("%lld\n",min(1ll*ans,Solve()));
	return 0;
}