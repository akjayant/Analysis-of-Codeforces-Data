#include<bits/stdc++.h>
#define cp complex<double>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXINF=2147483647;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-6;
const int MAXN=100005;
const ll MOD=1e9+7;

int read(){
	int s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

ll readll(){
	ll s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

char ch[MAXN];
int n;
ll dp[MAXN],pre[MAXN];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	ch[0]='#';
	ch[n+1]='@';
	dp[1]=0;
	dp[0]=1;
	pre[0]=1;
	pre[1]=1;
	for (register int i=2;i<=n;++i){
		dp[i]=pre[i-2];
		pre[i]=(pre[i-1]+dp[i])%MOD;
	}
	/*
	for (register int i=1;i<=n;++i){
		printf("%lld ",dp[i]);
	}
	printf("\n");
	for (register int i=1;i<=n;++i){
		printf("%lld ",pre[i]);
	}
	*/
	int su=0,sn=0;
	ll ans=1;
	for (register int i=1;i<=n+1;++i){
		if (ch[i]=='w' || ch[i]=='m'){
			printf("0");
			return 0;
		}
		if (ch[i]=='u'){
			su++;
		}
		else{
			ans=(ans*pre[su])%MOD;
			su=0;
		}
		if (ch[i]=='n'){
			sn++;
		}
		else{
			ans=(ans*pre[sn])%MOD;
			sn=0;
		}
	}
	cout<<ans;
	return 0;
}
