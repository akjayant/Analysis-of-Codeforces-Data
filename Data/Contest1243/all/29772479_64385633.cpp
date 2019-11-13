#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1010;
int a[N],n,res,T;
int dp[20][2][10][10][2][2][2],l,r,flag;
int dfs(int pos,int pre,int st,int ok,int limit,int is4,int is8){
	if(is4&&is8)	return 0;
	if(!pos)	return ok;
	if(dp[pos][ok][pre][st][limit][is4][is8]!=-1)	
		return dp[pos][ok][pre][st][limit][is4][is8];
	int up=limit?a[pos]:9,res=0;
	for(int i=0;i<=up;i++){
		res+=dfs(pos-1,i,pre,ok||i==pre&&pre==st,limit&&i==up,i==4||is4,i==8||is8);
	}
	dp[pos][ok][pre][st][limit][is4][is8]=res;
	return res;
}
int solve(int x){
	if(x<1e10)	return 0;	int res=0;
	int pos=0; memset(dp,-1,sizeof dp);
	while(x)	a[++pos]=x%10,x/=10;
	for(int i=1;i<=a[pos];i++)	res+=dfs(pos-1,i,0,0,i==a[pos],i==4,i==8);
	return res;
}
int cmp(int a,int b){
	return a>b;
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i];
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++)
			if(a[i]>=i)	res=i;
			else	break;
		cout<<res<<endl;
	}
	return 0;
}