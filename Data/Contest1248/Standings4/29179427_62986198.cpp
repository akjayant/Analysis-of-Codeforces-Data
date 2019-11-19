#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*ll pow(ll n,ll m){
    if(m==0)
       return 1;
    if(m==1)
       return n;
    ll k=1;   
    ll z=pow(n,m/2)%mod;
    if(m%2==1)
        k=n;
    ll ans=(((n*z)%mod)*z)%mod;
    return ans;
}*/
int main() {
    ll t;
    t=1;
    //cin>>t;
	ll n,m;
	
	
	while(t--){
	    cin>>n;
	    ll arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    
	    ll x;
	    if(n%2)
	       x=n/2-1;
	    else
	       x=n/2-1;
	    
	    ll a=0,b=0;
	    for(int i=0;i<=x;i++){
	        a+=arr[i];
	    }
	    for(int i=x+1;i<n;i++){
	        b+=arr[i];
	    }
	    
	    
	    cout<<a*a+b*b<<endl;
	    
	    
	}
	    
	
}