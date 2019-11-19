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


int n,k;
int a[101010];

void solve(){

	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = a[1], r = a[n];
	int cl = 1, cr = 1;
	int lef = 1, rig = n;
	while(l<r && k>0 ){
		//cout << l  << " " << r << " " << cl << " " << cr << endl;
		if(cl<=cr){
			int d = a[lef+1]-a[lef];
			int cost = d*cl;
			if(k>=cost){
				lef++;
				l = a[lef];
				cl++;
				k-=cost;
			}
			else {
				int t = k/cl;
				l+= t;
				k-= (t*cl);
			}
		}
		else {
			int d = a[rig] - a[rig-1];
			int cost = d*cr;
			if( k>=cost ){
				rig--;
				r = a[rig];
				cr++;
				k-=cost;
			}
			else {
				int t = k/cr;
				r-= t;
				k-= (t*cr);
			}
		}
		if( cr>k && cl>k )break;
	}
	cout << r-l << endl;

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
