#include<bits/stdc++.h> 
using namespace std;
 
#define ll long long int
#define absdiff(a,b) (a>b)?a-b:b-a
#define debug cout<<"debug";
#define mp make_pair 
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD  1000000007
#define ll_MAX 92233720368599
#define endl "\n"
ll fast_expo(ll x,ll p){if(p==0) return 1;
else if(p%2==0){ ll t=fast_expo(x,p/2)%MOD;return (t*t)%MOD;} else return (x*(fast_expo(x,p-1))%MOD)%MOD;}
ll gcd(ll a,ll b){if(a==0||b==0) return a+b;  else return gcd(b%a,a); }

int main(){
     ll q=1;
    //  cin>>q;
     for(ll x=0;x<q;++x){
          ll n,m;cin>>n>>m;
          ll first=fast_expo(2ll,m)-1;
          ll ans=fast_expo(first,n);
          cout<<ans;
     }
     return 0;
}