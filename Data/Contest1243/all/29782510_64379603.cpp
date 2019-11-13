#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define p2(a,b) cout<<a<<" "<<b<<endl;
#define p3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;	
#define all(a) a.begin(),a.end()
#define M 1000000007

	
int main(){
	fastio;
	int t,n;
	string s1,s2;
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2;
		vector<int> diff;
		for(int i=0;i<n;i++){
			if(s1[i]!=s2[i]){
				diff.pb(i);
			}
		}
		bool ans=false;
		if(diff.size()==0) ans=true;
		if(diff.size()==2){
			if(s1[diff[0]]==s1[diff[1]] && s2[diff[0]]==s2[diff[1]]) ans=true;
		}
		if(ans) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}