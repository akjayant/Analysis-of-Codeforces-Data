#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=1e5+5;
const int mod=1e9+7;
char ch[MN];
int n,f[MN];
int main(){
	scanf("%s",ch+1);n=strlen(ch+1);
	for(reg int i=1;i<=n;i++)
		if(ch[i]=='m'||ch[i]=='w')return 0*puts("0");
	f[1]=1;f[2]=2;f[3]=3;f[4]=5;
	for(reg int i=5;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	reg int Ans=1;
	for(reg int i=1,j=1;i<=n;i=j+1){
		j=i;
		if(ch[i]!='n'&&ch[i]!='u')continue;
		while(j<n&&ch[i]==ch[j+1])j++;
		Ans=1ll*Ans*f[j-i+1]%mod;
	}
	printf("%d\n",Ans);
	return 0;
}