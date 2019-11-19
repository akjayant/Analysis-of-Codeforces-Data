#include <bits/stdc++.h>
using namespace std;

int n,m;
int dp[100005];
const int Mod=1000000007;

int main(){
	scanf("%d%d",&n,&m);
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<100005;i++){
		dp[i]=(dp[i-1]+dp[i-2])%Mod;
	}
	printf("%d\n",(((dp[n]+dp[m])%Mod*2)%Mod+Mod-2)%Mod);
	return 0;
}