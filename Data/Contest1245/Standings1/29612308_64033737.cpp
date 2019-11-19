#include<bits/stdc++.h>

using namespace std;

long long f[33][3][3][3][3];

long long dfs(int u,int l,int r,int fa,int fb,int ffa,int ffb){
	if(u<0){
		return 1;
	}
	if(~f[u][fa][fb][ffa][ffb]){
		return f[u][fa][fb][ffa][ffb];
	}
	long long rep=0;int ra,rb;
	if(ffa){
		ra=(l>>u)&1;
	}
	else{
		ra=1;
	}
	if(ffb){
		rb=(r>>u)&1;
	}
	else{
		rb=1;
	}
	for(int i=0;i<=ra;i++){
		for(int j=0;j<=rb;j++){
			if(i+j<2){
				rep+=dfs(u-1,l,r,fa,fb,ffa&(i==ra),ffb&(j==rb));
			}
		}
	}
	return f[u][fa][fb][ffa][ffb]=rep;
}

long long solve(int l,int r){
	memset(f,-1,sizeof f);
	return dfs(31,l,r,0,0,1,1);
}

int t,l,r;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&r);
		if(!l){
			printf("%lld\n",solve(r,r));
		}
		else{
			printf("%lld\n",solve(r,r)-(solve(l-1,r)<<1)+solve(l-1,l-1));
		}
	}
	return 0;
}