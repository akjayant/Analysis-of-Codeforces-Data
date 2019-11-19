#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		string s;cin>>s;
		int n=s.length();
		int ans=n;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				ans=max(ans,2*(i+1));
				ans=max(ans,2*(n-i));
			}
		}
		cout<<ans<<endl;
	}
}
