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
    ll t,n,a,b,c;
    //t=1;
    cin>>t;
	
	while(t--){
	    cin>>n>>a>>b>>c;
	    string s;
	    cin>>s;
	    ll x=0,y=0,z=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='R'){
	            x++;
	        }
	        else if(s[i]=='P'){
	            y++;
	        }
	        else{
	            z++;
	        }
	    }
	    
	    ll ans=0;
	    if(b>=x){
	        ans+=x;
	    }
	    else{
	        ans+=b;
	    }
	    
	    if(c>=y){
	        ans+=y;
	    }
	    else{
	        ans+=c;
	    }
	    
	    
	    if(a>=z){
	        ans+=z;
	    }
	    else{
	        ans+=a;
	    }
	    char arr[1000]={};
	    if(ans>=(ceil(n/2.0))){
	        cout<<"YES"<<endl;
	        x=a;
	        y=b;
	        z=c;
	        // x=r, y=p , z=s
	        for(int i=0;i<n;i++){
	          if(s[i]=='R' && y>0){
	            arr[i]='P';
	            y--;
	          }
	          else if(s[i]=='P' && z>0){
	            arr[i]='S';
	            z--;
	          }
	          else if(s[i]=='S' && x>0){
	            arr[i]='R';
	            x--;
	          }   
	        }
	        
	        for(int i=0;i<n;i++){
	            if(arr[i]=='\0'){
	                if(x>0){
	                    arr[i]='R';
	                    x--;
	                }
	                else if(y>0){
	                    arr[i]='P';
	                    y--;
	                }
	                else if(z>0){
	                    arr[i]='S';
	                    z--;
	                }
	            }
	        }
	        
	        for(int i=0;i<n;i++){
	            cout<<arr[i];
	        }
	        cout<<endl;
	      }
	    else{
	        cout<<"NO"<<endl;
	    }
	    
	    
	}
	    
	
}