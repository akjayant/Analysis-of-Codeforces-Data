#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int mod=1e9+7;
const int maxn=1e5+5;
int n,f[maxn];
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	int ans=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='m'||s[i]=='w'){
			puts("0");return 0;
		}
		if(s[i]=='u'){
			int sum=1;
			while(s[i+1]=='u'){
				i++;sum++;
			}
			ans=1ll*ans*f[sum]%mod;
		}
		if(s[i]=='n'){
			int sum=1;
			while(s[i+1]=='n'){
				i++;sum++;
			}
			ans=1ll*ans*f[sum]%mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

