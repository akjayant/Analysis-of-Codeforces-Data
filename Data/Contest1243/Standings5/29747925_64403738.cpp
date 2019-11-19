#include<bits/stdc++.h>	
#define int long long int
#define pb push_back
#define endl "\n"
#define F first
#define S second 
#define mod 1000000007     
using namespace std;
main()
{	
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<int>v;
	for(int i=2; i*i<=n; i++){
		if(n%i==i and n%i==0){
			v.pb(i);
		}
		else if(n%i==0){
			v.pb(i);
			v.pb(n/i);
		}
	}
	if(v.size()==0){
		cout<<n;
		return 0;
	}
	sort(v.begin(), v.end());
	int var=0;
	for(int i=0; i<v.size(); i++){
		var=__gcd(var, v[i]);
	} 
	cout<<var;
}