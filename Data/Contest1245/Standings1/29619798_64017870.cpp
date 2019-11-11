#include<stdio.h>
#define inf 1000000007
char c[100002];
int f[100002],cnt=0,ans=1;
int main(){
	f[0]=f[1]=1;
	for(int i=2;i<=100000;i++)f[i]=(f[i-1]+f[i-2])%inf;
	scanf("%s",c+1);
	for(int i=1;c[i];i++){
		if(c[i]!=c[i-1])ans=1ll*ans*f[cnt]%inf,cnt=0;
		cnt+=c[i]=='u'||c[i]=='n';
		if(c[i]=='w'||c[i]=='m')return printf("0")&0;
	}printf("%lld",1ll*ans*f[cnt]%inf);
}