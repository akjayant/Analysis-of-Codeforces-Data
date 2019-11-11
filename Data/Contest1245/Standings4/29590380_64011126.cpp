#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MAXN @
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
const int mod = 1000000007;

int dp[202020];
int ans = 1;

void solve(){

	string s;
	cin >> s;
	dp[0] = 1;
	for(int i=0;i<=200000;i++){
		dp[i+1] = ( dp[i]+dp[i+1] )%mod;
		dp[i+2] = ( dp[i]+dp[i+2] )%mod;
	}
	int n = s.size();
	// for(int i=1;i<=10;i++){
	// 	cout << dp[i] << endl;
	// }
	int nn = 0, w = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='w' || s[i]=='m'){
			cout << 0 << endl;
			return ;
		}
		if(s[i] == 'n'){
			nn++;
			if(w){
				ans = ans*dp[w]%mod;
			}
			w = 0;
		}
		else if(s[i]=='u'){
			w++;
			if(nn){
				ans = ans*dp[nn]%mod;
			}
			nn = 0;
		}
		else {
			if( nn || w ){
				int x = max(nn,w);
				ans = ans*dp[x]%mod;
			}
			nn = 0;
			w = 0;
		}
	}
	if( nn || w ){
			int x = max(nn,w);
			ans = ans*dp[x]%mod;
	}
	cout << ans << endl;

}



signed main(){

#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
#endif

ios::sync_with_stdio(false);
cin.tie(0);

cout.precision(8);

  int t = 1;
  while(t--)
  solve();

cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

return 0;

}
