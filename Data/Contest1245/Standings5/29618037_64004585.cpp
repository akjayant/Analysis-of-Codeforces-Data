#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1e6+69;
const ll infll=1e18+69;
const ll mod=1e9+7;
const ld pi=acos(-1.0L);
#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define	ed return 0
#define hi hfvjidwkofiuhgaew
#define all(v) v.begin(), v.end()
int gcd(int a, int b){
	if(a<b) swap(a, b);
	if(b==0) return a;
	return gcd(b, a%b);
}
vector<ll>dp(100069);
int main(){
	fio;
	dp[1]=1ll; dp[2]=2ll;
	for(int i=3; i<100069; i++)
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	string s; cin>>s;
	int n=s.size();
	bool impos=false;
	for(int i=0; i<n; i++){
		if(s[i]=='w' || s[i]=='m'){
			impos=true; break;
		}
	}
	if(impos){ 
		cout<<0<<endl; return 0;
	}
	ll ans=1ll;
	vector<int>cnt;
	char last='-'; int cntt=0;
	for(int i=0; i<n; i++){
		if(last!=s[i]){
			if(last=='n' || last=='u')
				cnt.push_back(cntt);
			last=s[i];
			cntt=0;
		}
		cntt++;
	}
	if(last=='n'||last=='u') cnt.push_back(cntt);
	for(int i=0; i<cnt.size(); i++){
		ans=(ans*dp[cnt[i]])%mod;
	}
	cout<<ans<<endl;
	ed;
}