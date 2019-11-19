#include <bits/stdc++.h>
#define MOD 1000000007
#define MOD1 998244353
#define ll long long int
#define endl "\n"
#define INF 1e+18
#define INF1 1e+9
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
//#define mp make_pair
#define debx cout<<" X "<<endl;
#define deby cout<<" Y "<<endl;
#define debz cout<<" Z "<<endl;
using namespace std;

ll mpow(ll a, ll b){
    if(!b)
        return 1;
    ll temp=mpow(a,b/2);
    temp=(temp*temp)%MOD;
    if(b%2)
        return (a*temp)%MOD;
    return temp;
}
ll fn(ll a, ll b){
    if(a%b)
        return 1+a/b;
    return a/b;
}

int main(){
      fastio;
    ll t;
    cin>>t;
    while(t--){
        ll n,m,o1=0,e1=0,o2=0,e2=0;
        cin>>n;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            if(x%2)
                o1++;
            else
                e1++;
        }
        cin>>m;
        for(ll i=0;i<m;i++){
            ll x;
            cin>>x;
            if(x%2)
                o2++;
            else
                e2++;
        }
        cout<<(o1*o2+e1*e2)<<endl;
    }
}
