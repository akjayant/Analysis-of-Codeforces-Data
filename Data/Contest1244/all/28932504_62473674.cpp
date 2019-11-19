#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		
		ll n;
		cin>>n;
		string s;
		cin>>s;
		
		ll lo=-1,fo=-1;
		
		for(ll i=0;i<n;i++){
			if(s[i]=='1' && fo==-1){
				fo=i+1;
			}if(s[i]=='1'){
				lo=i+1;
			}
			
		}
		
		
		if(lo==-1){
			cout<<n<<endl;
			continue;
		}
		
		
		ll ans=2*lo;
		ans=max(ans,2*(n-fo+1) );
		cout<<ans<<endl;
		
	}
	
	
	return 0;
}
