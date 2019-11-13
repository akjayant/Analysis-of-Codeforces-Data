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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a, b;
		cin>>a>>b;
		vector<pair<char, char>>v;
		for(int i=0; i<n; i++){
			if(a[i]!=b[i]) v.pb({a[i], b[i]});
		}
		if(v.size()==0){
			cout<<"Yes";
			cout<<endl;
			continue;
		}
		if(v.size()!=2){
			cout<<"No";
			cout<<endl;
			continue;
		}
		else{
			if(v[0].F==v[1].F and v[0].S==v[1].S) cout<<"Yes";
			else cout<<"No";
		}
		cout<<endl;
	}

}