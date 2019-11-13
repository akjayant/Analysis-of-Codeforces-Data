// Kya dekhega re chokre
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define ln endl	

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
const double EPS = 1e-9;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	string s;
	cin>>s;

	int rm = 0, rw = 0;
	bool p = 1;
	int n = s.length();
	v64 v;

	forn(i,s.length()){
		if(s[i] == 'w' || s[i] == 'm') p = 0;
		if(s[i] == 'n'){
			if(rw>0){
				if(rw>1) v.pb(rw);
				rw = 0;
				rm = 1;
			}
			else rm++;
		}
		else if(s[i] == 'u'){
			if(rm>0){
				if(rm>1) v.pb(rm);
				rm = 0;
				rw = 1;
			}
			else rw++;
		}
		else{
			if(rm>1) v.pb(rm);
			if(rw>1) v.pb(rw);
			rm = 0;
			rw = 0;
		}
	}
	if(rm>1) v.pb(rm);
	if(rw>1) v.pb(rw);

	ll ans = 1;

	ll dp[LIM][2];

	forn(i,LIM){
		forn(j,2) dp[i][j] = 0;
	}
	dp[0][0] = 1;
	forsn(i,1,LIM){
		dp[i][0] = dp[i-1][0]+dp[i-1][1];
		dp[i][1] = dp[i-1][0];
		dp[i][0] %= MOD;
		dp[i][1] %= MOD;
	}

	forstl(r,v){
		ans *= (dp[r-1][0]+dp[r-1][1]);
		ans %= MOD;
	}


	if(p) cout<<ans<<ln;
	else cout<<0<<ln;

	return 0;
}