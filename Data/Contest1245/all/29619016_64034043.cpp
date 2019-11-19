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
    

	ll vis[3000]={};
	while(t--){
	    ll n;
	    cin>>n;
	    pair<ll,ll> arr[n+1];
	    pair<ll,ll> fans[n+1];
	    
	    for(int i=1;i<=n;i++){
	        cin>>arr[i].first>>arr[i].second;
	        fans[i].first=0;
	        fans[i].second=0;
	    }
	    
	    ll c[n+1],k[n+1],ans[n+1];
	    ll mn=1000000001,mid=-1;
	    for(int i=1;i<=n;i++){
	        cin>>c[i];
	        ans[i]=c[i];
	        if(c[i]<mn){
	            mn=c[i];
	            mid=i;
	        }
	    }
	    
	    for(int i=1;i<=n;i++){
	        cin>>k[i];
	    }
	    ll x=1;
	    
	    while(x<=n){
	        ll z=0;
	        vis[mid]=1;
	        ll a=arr[mid].first,b=arr[mid].second;
	        ll as=1000000007;
	        
	        ll tmp=mid;
	        ll mn=1000000007;
	        for(int i=1;i<=n;i++){
	            ll c=arr[i].first,d=arr[i].second;
	            if(mid!=i && vis[i]==0){
	               ll sum=abs(a-c)+abs(b-d);
	               sum*=k[i]+k[tmp];
	               
	               if(sum<ans[i]){
	                   ans[i]=sum;
	                   fans[i]={tmp,i};
	                   z=1;
	               }
	               
	               if(ans[i]<mn){
	                   mn=ans[i];
	                   mid=i;
	               }
	               
	            }
	        }
	        
	       
	        
	        x++;
	    }
	    
	    ll sum=0;
	    ll pc=0;
	    for(int i=1;i<=n;i++){
	        if(fans[i].first==0)
	           pc++;
	        sum+=ans[i];
	    }
	    
	    
	   cout<<sum<<endl;
	   cout<<pc<<endl;
	   for(int i=1;i<=n;i++){
	        if(fans[i].first==0)
	           cout<<i<<" ";
	        
	    }
	    cout<<endl;
	    cout<<n-pc<<endl;
	    
	    for(int i=1;i<=n;i++){
	        if(fans[i].first!=0)
	           cout<<fans[i].first<<" "<<fans[i].second<<endl;
	        
	    }
	    
	    
	}
	    
	
}