#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 500000
#define MOD 1000000007
#define DB double
#define LL long long
#define Pr pair<int,int>
#define X first
#define Y second
LL read(){
   	LL x=0,F=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
   	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*F;
}
int n,m,ans;
LL dp[MAXN+5][2],f[MAXN+5][2];
int main()
{
	n=read();m=read();
	dp[0][0]=1;dp[0][1]=1;
	for(int i=1;i<=n;i++){
		dp[i][1]=(dp[i-1][0]+((i>=2)?dp[i-2][0]:0))%MOD;
		dp[i][0]=(dp[i-1][1]+((i>=2)?dp[i-2][1]:0))%MOD;
	}
	f[0][0]=1;f[0][1]=1;
	for(int i=1;i<=m;i++){
		f[i][1]=(f[i-1][0]+((i>=2)?f[i-2][0]:0))%MOD;
		f[i][0]=(f[i-1][1]+((i>=2)?f[i-2][1]:0))%MOD;
	}
	printf("%lld",((f[m][0]+f[m][1])%MOD+(dp[n][0]+dp[n][1])%MOD-2+MOD)%MOD);
}