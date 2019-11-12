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
		vector<int>arr (n);
		int ans=0;
		for(int i=0; i<n; i++) cin>>arr[i];
		sort(arr.begin(), arr.end());
		//reverse(arr.begin(), arr.end());
		for(int i=0; i<n; i++){
			ans=max(min(n-i, arr[i]), ans);
		}
		cout<<ans<<endl;
	}
}