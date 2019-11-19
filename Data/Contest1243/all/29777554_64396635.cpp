#include<iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define pi acos(-1.0)
#define pf(a) cout<<"a "<<a<<endl;
#define ii pair<long long , long long>
#define mem(a,x) memset(a,x,sizeof(a))
#define fast ios_base::sync_with_stdio(0),cin.tie(0)
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
using namespace std;
using namespace __gnu_pbds;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {cout<<endl;}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ",   ";
    deb(++it, args...);
}

typedef tree< ll , null_type, less< ll >, rb_tree_tag, tree_order_statistics_node_update > order_set;

ll Pow(ll base,ll power) {ll ans=1; while(power){if(power&1)ans=(ans*base);base=(base*base);power>>=1;}return ans;}
ll BigMod(ll base,ll power,ll mod) {ll ans=1; while(power){if(power&1)ans=(ans*base)%mod;base=(base*base)%mod;power>>=1;}return ans;}
ll ModInverse(ll power,ll mod) {return BigMod(power,mod-2,mod);}

/*--------------------Code starts here-----------------------*/

const ll mx=2e6+7;

bool isprime[mx];
ll prime[mx];
ll cp;

void sieve(){
    isprime[1]=1;
    cp=0;
    prime[cp++]=2;

    for(ll i=4;i<mx;i+=2){
        isprime[i]=1;;
    }
    //cout<<"22222"<<endl;
    for(ll i=3;i<mx;i+=2){
        if(isprime[i]==0){
            prime[cp++]=i;
            //cout<<i<<" 3333"<<endl;
            if(i*i<mx){
                for(ll j=i*i;j<mx;j+=2*i){
                    isprime[j]=1;
                }
            }
        }
    }

}



int main(){
    sieve();
    ll n;
    cin>>n;

    ll cnt=0;
    ll num=n;
    ll pp=-1;
    for(ll i=0;prime[i]*prime[i]<=n && i<cp;i++){
        if(num%prime[i]==0){
            cnt++;
            pp=prime[i];
            while(num%prime[i]==0){
                num/=prime[i];
            }
        }
    }
    if(num>1 && num!=n){
        cnt++;
    }
    if(cnt==0){
        cout<<n<<endl;
    }
    else if(cnt==1){
        cout<<pp<<endl;
    }
    else cout<<1<<endl;


    return 0;
}
