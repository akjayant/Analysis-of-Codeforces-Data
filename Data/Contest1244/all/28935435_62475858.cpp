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





void solve(){

	int n;
	string s;
	cin >> n >> s;
	int mn = n,mx = -1;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			mn = min(mn, i);
			mx = max(mx, i);
		}
	}
	if(s[0]=='1' || s[n-1]=='1' ){
		cout << 2*n << endl;
		return ;
	}
	if(mn>mx){
		cout << n << endl;
	}
	else if(mn==mx){
		int ans = max( 2*(mn+1) , 2*(n-mn) );
		cout << ans << endl;
		//cout << n+1 << endl;
	}
	else {
		int ans = n;
		// ans = max(ans, mn+ 2*(mx-mn+1) );
		// ans = max(ans, n-mx-1 + 2*(mx-mn+1));
		// ans = max(ans, n+2);
		ans = max(ans, 2*(mx+1) );
		ans = max(ans, 2*(n-mn) );
		cout << ans << endl;
	}


}



signed main(){

#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
#endif

ios::sync_with_stdio(false);
cin.tie(0);

cout.precision(8);

  int t = 1;
  cin >> t;
  while(t--)
  solve();

cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

return 0;

}
