#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define pii pair<int,int>
#define io(); freopen("in.txt","r",stdin); freopen("output.txt","w",stdout); 
#define fast(); ios_base::sync_with_stdio(false);
#define all(x) x.begin(),x.end()
int32_t main(){
	fast();
    #ifndef ONLINE_JUDGE
    io();
    #endif
    int t,n,i,j;
    cin>>t;
    while(t--){
    	cin>>n;
    	vector<int>v(n);
    	for(i=0;i<n;i++) cin>>v[i];
    	sort(all(v));
    	reverse(all(v));
    	int ans=1;
    	for(i=0;i<n;i++){
    		if(v[i]>i) ans=i+1;
    	}
    	cout<<ans<<endl;
    }
}