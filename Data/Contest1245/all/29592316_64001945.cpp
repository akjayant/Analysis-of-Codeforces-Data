// Do you knOW what it feels like?
 
		// To be TorTured by your own MinD?
	
	// I don't wanna feel the PAIN.
 
// I BeG you to KILL me, pleASE...
 
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define SZ(x) (long long)(x.size())
#define all(x) x.begin(),x.end()
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;

const ll maxn=1e2+10, LG=18, mod=1e9+7, inf=1e18;

ll dp[maxn][maxn][maxn];
char par[maxn][maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	ll T; cin>>T;
	while(T--){
		ll n; cin>>n;
		ll a,b,c; cin>>a>>b>>c;
		string s; cin>>s;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)for(int k=0;k<=c;k++){
			if(i+j+k==0) continue;
			if(i){
				if(dp[i][j][k]<dp[i-1][j][k]+ (s[i+j+k-1]=='S') )
					dp[i][j][k]=dp[i-1][j][k]+ (s[i+j+k-1]=='S'), par[i][j][k]='R';
			}
			if(j){
				if(dp[i][j][k]<dp[i][j-1][k]+ (s[i+j+k-1]=='R') )
					dp[i][j][k]=dp[i][j-1][k]+ (s[i+j+k-1]=='R'), par[i][j][k]='P';
			}
			if(k){
				if(dp[i][j][k]<dp[i][j][k-1]+ (s[i+j+k-1]=='P') )
					dp[i][j][k]=dp[i][j][k-1]+ (s[i+j+k-1]=='P'), par[i][j][k]='S';
			}
		}
		if(dp[a][b][c]<(a+b+c+1)/2) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			ll aa=a,bb=b,cc=c;
			string ans="";
			while(aa+bb+cc){
				ans=par[aa][bb][cc]+ans;
				if(par[aa][bb][cc]=='R') aa--;
				else if(par[aa][bb][cc]=='P') bb--;
				else cc--;
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}































