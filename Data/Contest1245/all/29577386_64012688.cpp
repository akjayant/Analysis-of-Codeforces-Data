#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
//coded by _Int_
const int Mod=1000000007;
char s[100005];
int ln,n,u,ans=1,f[100005];
int main(){
	f[1]=1;f[2]=2;
	for(int i=3;i<=100000;i++)f[i]=(f[i-1]+f[i-2])%Mod;
	scanf("%s",s+1);
	ln=strlen(s+1);
	for(int i=1;i<=ln;i++){
		if(s[i]=='w'||s[i]=='m'){
			puts("0");
			return 0;
		}
		if(s[i]=='n'){
			n++;
			if(u)ans=(1ll*ans*f[u])%Mod,u=0;
		}
		else if(s[i]=='u'){
			u++;
			if(n)ans=(1ll*ans*f[n])%Mod,n=0;
		}
		else{
			if(u)ans=(1ll*ans*f[u])%Mod,u=0;
			if(n)ans=(1ll*ans*f[n])%Mod,n=0;
		}
	}
	if(u)ans=(1ll*ans*f[u])%Mod,u=0;
	if(n)ans=(1ll*ans*f[n])%Mod,n=0;
	printf("%d\n",ans);
	return 0;
}
/*
n=>1
nn=>2
nnn=>3
nnnn=>5

*/
