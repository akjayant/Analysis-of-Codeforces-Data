#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
 
#if DEBUG
    #include "debug.h"
#else
    #define debug(args...)
#endif    

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;


#define M 1000000 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = INT_MAX;
const int mod = 1e9+7;

const int N = 2e5 + 10;
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
clock_t time_p=clock();



int32_t main(){
	fast;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a,b,c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		// int cc[3] = {0};
		string ans(n,'#');
		int wins = 0;
		vector<char>v = {'R','P','S'};
		vector<char>vv = {'P','S','R'};
		vector<int>cc = {b,c,a};
		for(int j = 0; j < 3; j++) {
			for(int i = 0; i < s.length(); i++) {
				if(s[i] == v[j]) {
					if(cc[j] > 0) {
						ans[i] = vv[j];
						wins++;
						cc[j]--;
					}
				}
			}
		}
		if(wins >= (n + 1)/2) {
			cout << "YES\n";
			for(int j = 0; j < 3; j++) {
				for(int i = 0; i < n; i++) {
					if(cc[j] > 0 and ans[i] == '#') {
						ans[i] = vv[j];
						cc[j]--;
					}
				}
			}
			cout << ans << "\n";
		}
		else {
			cout << "NO\n";
		}
	}


	time_p=clock()-time_p;
	cerr<<"\nTime Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";

	return 0;
}