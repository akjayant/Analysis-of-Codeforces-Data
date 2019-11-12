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
		vector<vector<int>>v1;
		vector<vector<int>>v2;
		v1.resize(26);
		v2.resize(26);
		vector<pair<int, int>>ans;
		for(int i=0; i<n; i++){
			if(a[i]!=b[i]){
				v1[a[i]-'a'].pb(i+1);
				v2[b[i]-'a'].pb(i+1);
			} 
		}
		bool state=false;
		for(int i=0; i<26; i++){
			if((v1[i].size()+v2[i].size())%2==1){
				cout<<"No";
				cout<<endl;
				state=true;
				break;

			}
		}
		if(state) continue;
		
		bool con=false;
		for(int i=0; i<n; i++){
			if(a[i]!=b[i]){
				for(int j=i+1; j<n; j++){
					if(a[j]==a[i]){
						ans.pb({j+1, i+1});
						swap(a[j], b[i]);
						break;
					}
					else if(b[j]==a[i]){
						ans.pb({j+1, j+1});
						swap(a[j], b[j]);
						ans.pb({j+1, i+1});
						swap(a[j], b[i]);
						break;
					}
				}
			}
		}
		if(a[n-1]!=b[n-1]){
			cout<<"No";
			cout<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		cout<<ans.size()<<endl;
		for(auto to: ans){
			cout<<to.F<<" "<<to.S<<endl;
		}
	}
}