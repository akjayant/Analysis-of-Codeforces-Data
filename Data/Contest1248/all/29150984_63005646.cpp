#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define L long long
const L mod=1e9+7;
int n,m;
L f[2][2][100005];
int main(){
	scanf("%d%d",&n,&m);
	if(n>=2&&m>=2){
		f[0][0][1]=f[0][1][1]=f[1][0][1]=f[1][1][1]=1;
		for(int i=2;i<=100000;++i){
			f[0][0][i]=f[1][0][i-1]%mod;
			f[0][1][i]=(f[0][0][i-1]+f[1][0][i-1])%mod;
			f[1][0][i]=(f[1][1][i-1]+f[0][1][i-1])%mod;
			f[1][1][i]=f[0][1][i-1]%mod;
		}
		printf("%lld",(f[0][0][m-1]+f[0][1][m-1]+f[1][0][m-1]+f[1][1][m-1]+f[0][0][n-1]+f[0][1][n-1]+f[1][0][n-1]+f[1][1][n-1]-2)%mod);
		return 0;
	}
	if(n==1&&m==1){
		printf("2");
		return 0;
	}
	if(n==1||m==1){
		f[0][0][1]=f[0][1][1]=f[1][0][1]=f[1][1][1]=1;
		for(int i=2;i<=100000;++i){
			f[0][0][i]=f[1][0][i-1]%mod;
			f[0][1][i]=(f[0][0][i-1]+f[1][0][i-1])%mod;
			f[1][0][i]=(f[1][1][i-1]+f[0][1][i-1])%mod;
			f[1][1][i]=f[0][1][i-1]%mod;
		}
		if(n==1)printf("%lld",(f[0][0][m-1]+f[0][1][m-1]+f[1][0][m-1]+f[1][1][m-1])%mod);
		else printf("%lld",(f[0][0][n-1]+f[0][1][n-1]+f[1][0][n-1]+f[1][1][n-1])%mod);
	}
}