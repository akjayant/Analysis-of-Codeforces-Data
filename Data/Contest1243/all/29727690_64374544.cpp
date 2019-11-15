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

bool cumple(int w){
	int l = xd.size();
	int cuan = 0;
	for(int i = 0; i < l; i++){
		if(xd[i] >= w) cuan++;
	}

	if(cuan >= w) return true;
	else return false;
}

int main(){

	fastio;
  	int t;
  	cin >> t;

  	while(t--){
  		int n;
  		cin >> n;
  		xd.clear();
  		for(int i = 0; i < n; i++){
  			int a;
  			cin >> a;
  			xd.push_back(a);
  		}

  		for(int i = n; i >= 0; i--){
  			if(cumple(i)) {cout << i << endl; break;}
  		}
  	}

  	return 0;
}

