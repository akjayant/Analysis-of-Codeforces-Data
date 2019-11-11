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
    ll t,a,b;
    //t=1;
    cin>>t;
	
	while(t--){
	    cin>>a>>b;
	   // cout<<n<<endl;
	    if(__gcd(a,b)!=1){
	        cout<<"Infinite"<<endl;
	    }
	    else{
	        cout<<"Finite"<<endl;
	    }
	    
	}
	    
	
}