#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;
long long f[100010],ans=1,lenn,lenu;
char str[100010];
int n;

int main(){
	scanf("%s",str+1);f[0]=f[1]=1,f[2]=2;n=strlen(str+1);
	for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='m'||str[i]=='w'){printf("0");return 0;}
		if(str[i]=='u')lenu++;
		else ans=(ans*f[lenu])%mod,lenu=0; 
		if(str[i]=='n')lenn++;
		else ans=(ans*f[lenn])%mod,lenn=0;
	}
	ans=(ans*f[lenn])%mod;
	ans=(ans*f[lenu])%mod;
	cout<<ans;
	return 0;
}