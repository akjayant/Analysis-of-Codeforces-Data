#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
vector<int> g[2005];
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=n;

	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			int tempans=i+1;
			tempans=tempans+max(i+1,n-i);
			ans=max(tempans,ans);
		}
	}
	reverse(s.begin(),s.end());
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			int tempans=i+1;
			tempans=tempans+max(i+1,n-i);
			ans=max(tempans,ans);
		}
	}
	cout<<ans<<endl;
}
int32_t main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}

}