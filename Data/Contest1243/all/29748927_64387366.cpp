#include<bits/stdc++.h>
#define MOD 1000000007
#define INF LLONG_MAX
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define vc vector
#define vll vector<long long>
#define pll pair<long long,long long> 
#define pb push_back
#define all(v) v.begin(),v.end()
#define T ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define endl '\n'
#define MAX 100005
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n;
    cin>>n;
    vll d;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            d.pb(i);
            if(i*i!=n){
                d.pb(n/i);
            }
        }
    }
    if(d.size()==0){
        cout<<n;
    }else{
        ll g=0;

        rep(i,0,d.size()){
            g=__gcd(g,d[i]);
        }
        cout<<g;
    }




    return 0;
}

