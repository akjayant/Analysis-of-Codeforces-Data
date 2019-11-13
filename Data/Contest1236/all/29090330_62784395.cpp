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
		int a,b,c;
		cin>>a>>b>>c;
		int sz = 0;
		while(b>=1 && c>=2){
			b--;
			c-=2;
			sz+=3;
		}
		while(a>=1 && b>=2){
			a--;
			b-=2;
			sz+=3;
		}
		cout<<sz<<"\n";
	}
}

