#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<deque>
#include<climits>

#define mem(a) memset((a),0,sizeof((a)));
#define mod 1000000007
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define tv t[p].val
#define tl t[p].l
#define tr t[p].r
#define eps 1e-5
#define maxa 100005
using namespace std;

long long read(){
	long long xyz135=0,paage46=1;
	char cc1=getchar();
	while(cc1>'9'||cc1<'0'){
		if(cc1=='-')paage46=-1;
		cc1=getchar();
	}
	while(cc1>='0'&&cc1<='9'){
		xyz135=xyz135*10+cc1-'0';
		cc1=getchar();
	}
	return xyz135*paage46;
}
inline void read(long long&x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=((x<<1)+(x<<3))+c-'0';
		c=getchar();
	}
	return ;
}
inline void w1(long long x){
	if(x){
		w1(x/10);
		putchar(x%10+48);
	}
	return ;
}
inline void write(long long x){
	if(x)w1(x);
	else putchar('0');
	return ;
}
long long to[maxa],nxt[maxa],top=1,h[maxa];
void psh(long long u,long long v){
	to[++top]=v;nxt[top]=h[u];h[u]=top;
	to[++top]=u;nxt[top]=h[v];h[v]=top;
	return ;
}
long long n;
char c[maxa];
long long dp[maxa];
long long C(long long x){
	return dp[x];
}
main(){
	scanf("%s",c+1);
	n=strlen(c+1);
	dp[0]=dp[1]=1;
	for(long long i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=mod;
	}
	long long ans=1,u=0,v=0;
	for(long long i=1;i<=n;i++){
		if(c[i]=='w'||c[i]=='m')ans=0;
		if(c[i]=='u')u++;
		else ans=(ans*C(u))%mod,u=0;
		if(c[i]=='n')v++;
		else ans=(ans*C(v))%mod,v=0;
	}ans=(ans*C(u))%mod;ans=(ans*C(v))%mod;
	cout<<ans;
	return 0;
}
