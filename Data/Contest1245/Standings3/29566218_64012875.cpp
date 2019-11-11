//problem:
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MOD=1e9+7,MAXN=1e5+5;
int n,dp[MAXN][2];
int main() {
	dp[1][0]=1;
	dp[2][0]=dp[2][1]=1;
	for(int i=3;i<=100000;++i)dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD,dp[i][1]=(dp[i-2][0]+dp[i-2][1])%MOD;
	string s;
	cin>>s;
	n=s.length();
	int ans=1;
	for(int i=0;i<n;++i){
		if(s[i]=='m'||s[i]=='w'){ans=0;break;}
		if(s[i]=='u'||s[i]=='n'){
			int j=i+1;
			while(j<n&&s[j]==s[i])++j;
			--j;
			ans=(ll)ans*(dp[j-i+1][0]+dp[j-i+1][1])%MOD;
			i=j;
		}
	}
	cout<<ans<<endl;
	return 0;
}