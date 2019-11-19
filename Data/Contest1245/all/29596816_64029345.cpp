#include<bits/stdc++.h>
#define rep(q,a,b) for(int q=a,q##_end_=b;q<=q##_end_;++q)
#define dep(q,a,b) for(int q=a,q##_end_=b;q>=q##_end_;--q)
#define mem(a,b) memset(a,b,sizeof a )
using namespace std;
void in(int &r){
	static char c;
	r=0;
	bool flag=0;
	while(c=getchar(),!isdigit(c))if(c=='-')flag=1;
	do r=(r<<1)+(r<<3)+(c^48);
	while(c=getchar(),isdigit(c));
	if(flag)r=-r;
}
int L,R;
long long mul_3[40];
bool vis[35][2][2];
long long dp[35][2][2];
long long dfs(int now,bool lim_l,bool lim_r){
	if(now==-1)return 1;
	if(!lim_l&&!lim_r)return mul_3[now+1];
	if(vis[now][lim_l][lim_r])return dp[now][lim_l][lim_r];
	vis[now][lim_l][lim_r]=1;
	if(lim_l&&lim_r){
		long long s=0;
		if(L&(1<<now)){
			s+=dfs(now-1,1,!(R&(1<<now)));
		}
		if(R&(1<<now)){
			s+=dfs(now-1,!(L&(1<<now)),1);
		}
		s+=dfs(now-1,!(L&(1<<now)),!(R&(1<<now)));
		return dp[now][lim_l][lim_r]=s;
	}
	if(lim_l){
		if(L&(1<<now)){
			return dp[now][lim_l][lim_r]=dfs(now-1,1,0)+dfs(now-1,0,0)*2;
		}
		return dp[now][lim_l][lim_r]=dfs(now-1,1,0)*2;
	}
	if(R&(1<<now)){
		return dp[now][lim_l][lim_r]=dfs(now-1,0,1)+dfs(now-1,0,0)*2;
	}
	return dp[now][lim_l][lim_r]=dfs(now-1,0,1)*2;
}
long long get(int l,int r){
	if(l==-1||r==-1)return 0;
	mem(vis,0);
	L=l,R=r;
////	cout<<l<<' '<<r<<' '<<dfs(30,1,1)<<endl;
	return dfs(30,1,1);
}
int main(){
	mul_3[0]=1;
	rep(q,1,35)mul_3[q]=mul_3[q-1]*3;
	int T;
	in(T);
	int a,b;
	while(T--){
		in(a),in(b);
		printf("%I64d\n",get(b,b)-get(a-1,b)*2+get(a-1,a-1));
	}
	return 0;
} 