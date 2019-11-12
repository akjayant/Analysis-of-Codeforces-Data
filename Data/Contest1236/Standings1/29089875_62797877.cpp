#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair
#define pri 1000000007
using namespace std;
ll power(ll x, unsigned ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
}
void masterstroke(){
	ll n;
	cin>>n;
	vector <ll>grp[n+1];
	for(ll i=0;i<n*n;i++){
		ll p=i/n;
		if(p%2){
			grp[(i)%n].PB(i+1);
		}
		else{
			grp[n-i%n-1].PB(i+1);
		}
	}
	for(ll i=0;i<n;i++){
		for(auto j:grp[i]){
			cout<<j<<" ";
		}
		cout<<'\n';
	}
	
	}

int main() {
	//cout<<pri+3;
	ll t=1;
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	//cin>>t;
	for(ll i=0;i<t;i++)masterstroke();

	// your code goes here
	return 0;
}