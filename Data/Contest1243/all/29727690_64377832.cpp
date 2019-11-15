// TY Swistakk 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
typedef long double ld;
 
const ll N = 200050;
const ll N1 = 100500;
const ll mod = 1000000007;
 
using namespace std;
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);}
#else
#define trace(...)
#endif

vector <int> xd;



int main(){

	fastio;
  	int t;
  	cin >> t;

  	while(t--){
  		xd.clear();
  		int n;
  		cin >> n;

  		string s1, s2;
  		cin >> s1 >> s2;
  		for(int i = 0; i < n; i++){
  			if(s1[i] != s2[i]) xd.push_back(i);
  		}

  		if(xd.size() > 2) cout << "NO" << endl;
  		else{
  			if(xd.size() == 0) cout << "YES" << endl;
  			else if(xd.size() == 1) cout << "NO" << endl;
  			else{
  				if(s1[xd[0]] == s1[xd[1]] and s2[xd[0]] == s2[xd[1]]) cout << "YES" << endl;
  				else cout << "NO" << endl;
  			}
  		}
  	}

  	return 0;
}

