#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long 
using namespace std;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
const int num=35;
int dp[40][2][2];
int L[40],R[40];
int solve(int x,int y){
	if(x<0 || y<0)return 0;
	memset(dp,0,sizeof(dp));		
	for(register int i=0;i<=32;i++){L[i]=x%2;x>>=1;}
	for(register int i=0;i<=32;i++){R[i]=y%2;y>>=1;}
	dp[num][0][0]=1;
	for(register int i=num-1;i>=0;i--){
		//cout<<L[i]<<" "<<R[i]<<endl;
		for(register int j=0;j<=1;j++){
			for(register int k=0;k<=1;k++){
				int J=j||(L[i]),K=k||(R[i]);
				if(L[i]||j)dp[i][j][K]+=dp[i+1][j][k];
				if(R[i]||k)dp[i][J][k]+=dp[i+1][j][k];
				dp[i][J][K]+=dp[i+1][j][k];
			}
		}
	}
	//cout<<x<<" "<<y<<" "<<f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1]<<endl;
	return dp[0][0][0]+dp[0][0][1]+dp[0][1][0]+dp[0][1][1];
}

signed main(){
	int t=read();
	while(t--){
		int l=read(),r=read();
		printf("%lld\n",solve(r,r)-solve(l-1,r)*2+solve(l-1,l-1));
	}
	return 0;
}