#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector< vector<int> > ans(n);
	vector<int> v(n);
	for(int i = 0; i < n; i++) v[i] = i;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans[v[j]].pb(i*n+j);
		}
		reverse(v.begin(),v.end());
	}
	for(auto v1:ans){
		for(auto t:v1){
			cout<<t+1<<" ";
		}
		cout<<"\n";
	}
}

