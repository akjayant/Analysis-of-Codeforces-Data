#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll pow(ll n,ll m){
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
}
int main() {
    ll t;
    cin>>t;
	ll n,m;
	
	
	while(t--){
	    cin>>n;
	    
	    ll o1=0,o2=0,e1=0,e2=0;
	    ll x;
	    while(n--){
	        cin>>x;
	        if(x%2)
	           o1++;
	        else
	           e1++;
	    }
	    cin>>m;
	     
	     while(m--){
	        cin>>x;
	        if(x%2)
	           o2++;
	        else
	           e2++;
	    }   
	    
	    cout<<o1*o2+e1*e2<<endl;
	    
	    
	}
	    
	
}