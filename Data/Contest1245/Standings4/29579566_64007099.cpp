#include<bits/stdc++.h>
#define LL long long 
using namespace std;

inline int read(){
	int res=0,f=1;char ch=' ';
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
const int N=1e6+5;
const int mod=1000000007;
const double inf=100000000;
string s;
long long f[N];
long long ans=1;
int main(){
	f[1]=1;f[2]=2;
	for(register int i=3;i<N;i++) f[i]=(f[i-1]+f[i-2])%mod;
	cin>>s;
	for(register int i=0;i<s.length();i++){
		if(s[i]=='m'||s[i]=='w'){
			puts("0");return 0;
		}
		if(s[i]!='u'&&s[i]!='n') continue;
		int len=1;
		while(s[i]==s[i+1]){
			len++;i++;
		}
		ans=(1ll*ans*f[len])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}