#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define rv(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int M = 1200000;
const int inf = 0x3f3f3f3f;
const int md = 1e9+7;
int n,m,k;
char s[M];
int dp[M]={0};
int solve(){
	fo(i,1,n) if(s[i]=='m'||s[i]=='w') return 0;
	ll ans=1;
	fo(i,1,n) {
		int c=1;
		if(s[i]=='n'){
		while(i+1<=n&&s[i+1]=='n') {
			++i;++c;
		}
		}
		ans*=dp[c];
		ans%=md;
		c=1;
		if(s[i]=='u'){
		while(i+1<=n&&s[i+1]=='u'){
			++i;++c;
		}
		}
		ans*=dp[c];
		ans%=md;
	}
	return ans;
}
int main() {
	cin>>(s+1);
	n = strlen(s+1);
	dp[0]=dp[1]=1;
	fo(i,2,n) dp[i]=(dp[i-2]+dp[i-1])%md;
	cout<<solve()<<endl;
	return 0;
}
