#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

const int MN = 100005;

void solve(){
	int n,m;
	cin>>n;
	ll res=0;
	ll e=0,o=0;
	for(int i=0; i<n; ++i){
		ll a;
		cin>>a;
		if(a&1)o++;
		else e++;
	}
	cin>>m;
	for(int i=0; i<m; ++i){
		ll a;
		cin>>a;
		if(a&1)res+=o;
		else res+=e;
	}
	cout<<res<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0; i<t; ++i)solve();
	return 0;
}
