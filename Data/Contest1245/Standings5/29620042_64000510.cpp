#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 200005
#define mod 1000000007

ll ans;
vector<ll>v;
char s[N];
int n;
ll dp[N][2],sum[N];

int main(){
	
	dp[1][0]=1;
	dp[1][1]=0;
	dp[2][0]=1;
	dp[2][1]=1;
	for(int i=3;i<=200000;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		dp[i][1]=(dp[i-2][0]+dp[i-2][1])%mod;
	}
	
	
	
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='m' || s[i]=='w'){
			puts("0");return 0;
		}	
		
	s[0]=0;
	int len=0;
	for(int i=1;i<=n;i++){
		if(s[i]==s[i-1]){
			if(s[i]=='n'||s[i]=='u')len++;
			else len=0;
		}
		else {
			if(len)
				v.push_back(len); 
			if(s[i]=='n'||s[i]=='u')len=1;
			else len=0;
		}
	}
	if(len)
		v.push_back(len);
	
	ans=1;
	for(auto len:v){
		ans=ans*(dp[len][0]+dp[len][1])%mod;
	}
	cout<<ans<<'\n';
	
}
/*
nnnn
mnn
nmn
nnm
mm
*/
