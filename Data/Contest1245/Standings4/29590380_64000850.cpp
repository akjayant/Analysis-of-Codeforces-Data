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

	string str;
	int n,r,p,s;
	cin >> n >> r >> p >> s ;
	cin >> str;
	string ans = "";
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(str[i]=='R' && p ){
			p--;
			ans+= "P";
			cnt++;
			continue;
		}
		if(str[i]=='P' && s){
			s--;
			ans+= "S";
			cnt++;
			continue;
		}
		if(str[i]=='S' && r){
			r--;
			ans+= "R";
			cnt++;
			continue;
		}
		ans+= "-";
	}
	if(cnt < (n+1)/2){
		cout << "NO" << endl;
		return ;
	} 
	cout << "YES" << endl;
	for(int i=0;i<n;i++){
		if(ans[i]=='-'){
			if(p){
				ans[i] = 'P';
				p--;
				continue;
			}
			if(r){
				r--;
				ans[i] = 'R';
				continue;
			}
			if(s){
				s--;
				ans[i] = 'S';
				continue;
			}
		}
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
