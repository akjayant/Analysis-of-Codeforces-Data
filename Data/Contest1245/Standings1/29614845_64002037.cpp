#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl){cout<<_rpl<<endl;exit(0);}
int nextint(){int x;scanf("%d",&x);return x;}
ll nextll(){ll x;scanf("%lld",&x);return x;}
template<class T>T emax(T& t1,T t2){if(t1<t2)t1=t2;return t1;}
template<class T>T emin(T& t1,T t2){if(t1>t2)t1=t2;return t1;}

int read(){
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ret=ret*10+(c-'0');c=getchar();}
	return ret*f;
}

const ll mod=1e9+7;

char s[100005];
int len;
ll dp[100005];

bool judge(int p){
	if(s[p]=='u'&&s[p+1]=='u')return true;
	if(s[p]=='n'&&s[p+1]=='n')return true;
	return false;
}

int main(){
	scanf("%s",s);
	len=strlen(s);
	for(int i=0;s[i];++i){
		if(s[i]=='m'||s[i]=='w'){
			puts("0");
			return 0;
		}
	}
	if(len==1){
		puts("1");
		return 0;
	}
	dp[0]=1ll;
	dp[1]=(judge(0)?2ll:1ll);
	for(int i=2;i<len;++i){
		dp[i]+=dp[i-1];
		dp[i]%=mod;
		if(judge(i-1))dp[i]+=dp[i-2];
		dp[i]%=mod;
	}
	printf("%I64d\n",dp[len-1]);
	return 0;
}
