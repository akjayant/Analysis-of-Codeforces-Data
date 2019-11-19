#include<stdio.h>
int f[12][12],b[102];
double dp[102],pd[102];
int main(){
	for(int i=1;i<=10;i++){
		if(i&1)for(int j=1;j<=10;j++)f[i][j]=i*10+j-10;
		else for(int j=1;j<=10;j++)f[i][j]=i*10+1-j;
	}for(int i=10;i>=1;i--){
		for(int j=1;j<=10;j++){
			int p;scanf("%d",&p);
			if(p)b[f[i][j]]=f[i+p][j];
		}
	}dp[100]=pd[100]=0;
	dp[99]=pd[99]=6;
	dp[98]=pd[98]=6;
	dp[97]=pd[97]=6;
	dp[96]=pd[96]=6;
	dp[95]=pd[95]=6;
	for(int i=94;i>=1;i--){
		pd[i]=dp[i]=(pd[i+1]+pd[i+2]+pd[i+3]+pd[i+4]+pd[i+5]+pd[i+6])/6+1;
		if(b[i]&&pd[i]>dp[b[i]])pd[i]=dp[b[i]];
	}printf("%.7lf",pd[1]);
}