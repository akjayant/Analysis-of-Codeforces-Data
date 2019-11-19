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
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin>>v[i];
	sort(v.begin(),v.end());
	ll a = 0;
	ll b = 0;
	for(int i = 0; i < n/2; i++){
		a+=v[i];
		b+=v[n-1-i];
	}
	if(n%2==1) b+=v[n/2];
	cout<<a*a+b*b;
}

