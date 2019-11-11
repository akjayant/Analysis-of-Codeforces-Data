#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1e5+5,M=1e9+7;
char s[N];
int f[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1),ans=1,ln=0,lu=0;
	f[1]=1;f[2]=2;
	for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%M;
	for(int i=1;i<=n+1;i++){
		if(s[i]=='m'||s[i]=='w'){ans=0;break;}
		if(s[i]=='n')ln++;
		else if(ln){
			ans=1ll*ans*f[ln]%M;
			ln=0;
		}
		if(s[i]=='u')lu++;
		else if(lu){
			ans=1ll*ans*f[lu]%M;
			lu=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
