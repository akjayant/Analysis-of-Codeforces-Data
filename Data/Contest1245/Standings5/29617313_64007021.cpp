#include <bits/stdc++.h> 
#define N 100010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll read(){
	char c=getchar();bool flag=0;ll x=0;
	while(c<'0'||c>'9'){if(c=='-')flag=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return flag?-x:x;
}
char s[N];
const ll P=1e9+7;
ll dp[N];
int main(){
	scanf("%s",s+1);
	ll len=strlen(s+1);
	dp[0]=1;
	for(ll i=1;i<=len;i++){
		if(s[i]=='m'||s[i]=='w'){
			printf("0");
			return 0;
		}
		if(s[i]=='u'&&s[i-1]=='u') dp[i]=(dp[i-1]+dp[i-2])%P;
		else{
			if(s[i]=='n'&&s[i-1]=='n') dp[i]=(dp[i-1]+dp[i-2])%P;
			else dp[i]=dp[i-1]%P;
		}
	}
	printf("%lld",dp[len]);
}
