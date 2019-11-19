#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
typedef long long ll;

//const ll mod=1e9+7;

ll fact[100005];
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      
  
    x = x % p;
    while (y > 0) 
    { 
        
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  

ll nCr(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
    
  
    return (fact[n]* modInverse(fact[r], p) % p * 
            modInverse(fact[n-r], p) % p) % p; 
} 
  

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	ll mod=1e9+7;
	fact[0] = 1; 
    for (ll q=1 ; q<=100000; q++) 
        fact[q] = fact[q-1]*q%mod; 
	
	ll z,x;
	cin>>z>>x;
	ll ans=0;
	for(ll q=0;q<=100000;q++){
		if(q*2<=z){
			ll n=z-(q*2)+q;
			ans=((ans%mod) + ((nCr(n,q,mod)*2LL)%mod))%mod;
//			cout<<"yo  "<<q<<" "<<nCr(n,q,mod)<<endl;
		}
		else{
			break;
		}
	}
	for(ll q=0;q<=100000;q++){
		if(q*2<=x){
			ll n=x-(q*2)+q;
			ans=((ans%mod) + ((nCr(n,q,mod)*2LL)%mod))%mod;
//			cout<<"yo1  "<<q<<" "<<nCr(n,,mod)<<endl;
		}
		else{
			break;
		}
	}
	ans-=2LL;
	while(ans<0)ans+=mod;
	cout<<ans<<endl;
}