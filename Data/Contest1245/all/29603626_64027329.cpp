#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[35][2][2];
ll work(int l,int r){
	memset (dp,0,sizeof(dp));
	dp[31][1][1]=1;
	for (int i=31;i>=1;i--){
		for (int j=0;j<=1;j++){
			for (int k=0;k<=1;k++){
				if ((l&(1<<(i-1)))&&(r&(1<<(i-1)))){//11
					dp[i-1][0][0]+=dp[i][j][k];//00
					dp[i-1][0][k]+=dp[i][j][k];//01
					dp[i-1][j][0]+=dp[i][j][k];//10
				}else if ((l&(1<<(i-1)))&&(!(r&(1<<(i-1))))){//10
					dp[i-1][0][k]+=dp[i][j][k];//00
					dp[i-1][j][k]+=dp[i][j][k];//10
					if (!k) dp[i-1][0][0]+=dp[i][j][k];//01
				}else if ((r&(1<<(i-1)))&&(!(l&(1<<(i-1))))){//01
					dp[i-1][j][0]+=dp[i][j][k];//00
					dp[i-1][j][k]+=dp[i][j][k];//01
					if (!j) dp[i-1][0][0]+=dp[i][j][k];//10
				}else{//00
					dp[i-1][j][k]+=dp[i][j][k];//00
					if (!j) dp[i-1][0][k]+=dp[i][j][k];//10
					if (!k) dp[i-1][j][0]+=dp[i][j][k];//01
				}
			}
		}
	}
	return dp[0][0][0]+dp[0][0][1]+dp[0][1][0]+dp[0][1][1];
}
int main (){
	int T;scanf ("%d",&T);
	while (T--){
		int l,r;scanf ("%d%d",&l,&r);
		if (l==0&&r==0) puts("1");
		else if (l==0) printf ("%I64d\n",work(r,r));
		else printf ("%I64d\n",work(r,r)-work(l-1,r)*2+work(l-1,l-1));
	}
	return 0;
}
