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

const ll maxn=1e5+10, LG=18, mod=1e9+7, inf=1e18;



int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	ll dp[maxn];
	dp[0]=dp[1]=1;
	for(int i=2;i<maxn;i++) dp[i]=dp[i-1]+dp[i-2], dp[i]%=mod;
	
	string s; cin>>s;

	ll ans=1;
	for(int i=0;i<SZ(s);i++){
		if(s[i]=='u'){
			int j=i;
			while(j<SZ(s) && s[j]=='u') j++;
			ans*=dp[j-i], ans%=mod;
			i=j-1;
			continue;
		}
		if(s[i]=='n'){
			int j=i;
			while(j<SZ(s) && s[j]=='n') j++;
			ans*=dp[j-i], ans%=mod;
			i=j-1;
			continue;
		}
		if(s[i]=='m' || s[i]=='w') return cout<<0<<endl, 0;
	}
	cout<<ans<<endl;

	return 0;
}































