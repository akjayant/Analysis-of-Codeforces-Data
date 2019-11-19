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
	int t;
	cin>>t;
	while(t--){
		vector<ll> v(2);
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			int c;
			cin>>c;
			v[c%2]++;
		}
		int m;
		cin>>m;
		vector<ll> a(2);
		for(int i = 0; i < m; i++){
			int c;
			cin>>c;
			a[c%2]++;
		}
		cout<<v[0]*a[0]+v[1]*a[1]<<"\n";
	}
}

