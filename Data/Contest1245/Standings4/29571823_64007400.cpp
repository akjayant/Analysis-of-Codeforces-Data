#include<bits/stdc++.h>
typedef long long LL;
typedef double db;
#define REP(i,s,t) for(register int i=s;i<=t;++i)
#define PER(i,s,t) for(register int i=s;i>=t;--i)
#define FOREDGE(i,x,v) for(int i=fir[x],v=to[i];i;i=nex[i],v=to[i])
template<typename T>inline T in(){
    T ans=0;bool b=0;char ch=getchar();
    while(ch<'0'||ch>'9')b=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9')ans=ans*10+ch-48,ch=getchar();
    return b?-ans:ans;
}
#define II in<int>()
#define IL in<LL>()
//<-----QAQ----->
const LL mod=1e9+7;
LL ans,dp[100005];
char ch[100005];
int len;
int main(){
	scanf("%s",ch+1);ans=1;
	len=std::strlen(ch+1);
	dp[0]=dp[1]=1;
	REP(i,2,len)dp[i]=(dp[i-1]+dp[i-2])%mod;
	char op=0;int top=0;
	REP(i,1,len){
		if(ch[i]=='m')ans=0;
		if(ch[i]=='w')ans=0;
		if(ch[i]=='u'){
			if(op=='u')top++;
			else ans=ans*dp[top]%mod,top=1,op='u';
		}else if(ch[i]=='n'){
			if(op=='n')top++;
			else ans=ans*dp[top]%mod,top=1,op='n';
		}else{
			ans=ans*dp[top]%mod;
			top=0;op=0;
		}
	}
	ans=ans*dp[top]%mod;
	printf("%lld",ans);
}