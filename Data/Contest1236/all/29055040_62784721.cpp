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

	int a,b,c;
	cin >> a >> b >> c;
	int ans = 0;
	while(b>0 && c>1){
		ans+=3;
		c-=2;
		b-=1;
	}
	while(a>0 && b>1){
		ans+=3;
		b-=2;
		a-=1;
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
  cin >> t;
  while(t--)
  solve();

cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

return 0;

}
