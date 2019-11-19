#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007



int main() {
    ll t;
    t=1;
    //cin>>t;
	ll n,m;
	
	ll arr[1000001]={};
	arr[1]=2;
	arr[2]=4;
	arr[0]=2;
	for(ll i=3;i<=1000000;i++){
	    arr[i]=(arr[i-1]+arr[i-2])%mod;
	}
	
	while(t--){
	    cin>>n>>m;
	    
	    ll z=arr[n];
	    ll x=0,j=1;
	    for(ll i=1;i<m;i++){
	        
	        z=(z+arr[i-1])%mod;
	       // cout<<z<<endl;
	        x++;
	        if(x==n){
	           x=0;
	           j++;
	        }
	    }
	    
	    cout<<z<<endl;
	    
	    
	}
	    
	
}