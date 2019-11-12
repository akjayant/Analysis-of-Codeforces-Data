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


int n;
vector<int> ans[500];

void solve(){

	cin >> n;
	int cur = 1;
	int c = 1;
	for(int i=1;i<=n*n;i++){
		ans[cur].push_back(i);
		//cout << cur << " " << i << endl;
		if(c){
			cur++;
		}
		else {
			cur--;
		}
		if(cur>n){
			c^=1;
			cur--;
		}
		if(cur<1){
			c^=1;
			cur++;
		}
	}
	for(int i=1;i<=n;i++){
		for(auto t:ans[i]){
			cout << t << " ";
		}
		cout << endl;
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
  while(t--)
  solve();

cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

return 0;

}
