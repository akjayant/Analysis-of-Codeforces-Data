#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[33][2][2],a[33],b[33],n0,n1;
ll solve(ll n,ll m){
	if(min(n,m)<0)return 0;
	ll i,j,k,ii,jj,op0,op1;
	n0=n1=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(n){
		a[++n0]=n%2;
		n/=2;
	}
	while(m){
		b[++n1]=m%2;
		m/=2;
	}
	memset(f,0,sizeof(f));
	//for(i=1;i<=n0/2;i++)swap(a[i],a[n0-i+1]);
	//for(i=1;i<=n1/2;i++)swap(b[i],b[n1-i+1]);
	f[max(n0,n1)+1][1][1]=1;
	for(i=max(n0,n1);i;i--){
		for(j=0;j<=1;j++)
		 for(k=0;k<=1;k++){
		 	for(ii=0;ii<=1;ii++)
		 	 for(jj=0;jj<=1;jj++)if(ii!=1||jj!=1){
		 	 	if(!a[i]&&ii&&j)continue;
		 	 	if(!b[i]&&jj&&k)continue;
		 	 	op0=j&(ii==a[i]);
		 	 	op1=k&(jj==b[i]);
		 	 	f[i][op0][op1]+=f[i+1][j][k];
			  }
		 }
	}
	return f[1][0][0]+f[1][1][0]+f[1][1][1]+f[1][0][1];
}
int main(){
	ll l,r,t1,ans;
	scanf("%lld",&t1);
	while(t1--){
		scanf("%lld%lld",&l,&r);
		//printf("%lld %lld %lld\n",solve(r,r),solve(l-1,r),solve(l-1,l-1));
		//ans=solve(r,r);
		//printf("%lld %lld %lld %lld %lld\n",ans,l,r,solve(l-1,r),solve(l-1,r)*2);
		//ans-=solve(l-1,r)*2;
	//	printf("%lld\n",ans);
		//ans+=solve(l-1,l-1);
		//printf("%lld\n",ans);
		printf("%lld\n",solve(r,r)-solve(l-1,r)*2+solve(l-1,l-1));
	}
}