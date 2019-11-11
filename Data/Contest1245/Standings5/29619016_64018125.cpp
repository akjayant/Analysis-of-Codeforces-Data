#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


ll ispal(string s){
    ll n=s.length();
    if(n%2==1)
       return 2;
    int e=0,o=0;   
    for(int i=0;i<n;i++){
        if(s[i]=='0')
            o++;
    }
   // cout<<"o= "<<o<<endl;
    if(o%2==1)
       return 0;
    
    return 1;
}

int main() {
    ll t;
    t=1;
    
	ll arr[100001]={};
	arr[1]=1;
	arr[2]=2;
	
	for(ll i=3;i<=100000;i++){
	    arr[i]=(arr[i-1]+arr[i-2])%mod;
	}
	
	
	while(t--){
	    string s;
	    cin>>s;
	    ll ans=1;
	    ll n=0,u=0;
	    for(ll i=0;i<s.length();i++){
	        if(s[i]=='m' || s[i]=='w'){
	            cout<<0;
	            return 0;
	        }
	        
	        if(s[i]=='n'){
	            while( i<s.length() && s[i]=='n' ){
	                n++;
	                i++;
	            }
	            i--;
	            ans=(ans*arr[n])%mod;
	            n=0;
	        }
	        else if(s[i]=='u'){
	            while( i<s.length() && s[i]=='u'){
	                u++;
	                i++;
	            }
	            i--;
	            ans=(ans*arr[u])%mod;
	            u=0;
	        }
	       // cout<<n<<" "<<u<<endl;
	        
	        
	        
	    }
	    
	    cout<<ans;
	    
	}
	    
	
}