#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vii vector<pair<int,int> >
#define vll vector<pair<ll,ll> >

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    ll n;
    cin>>n;
    ll minfac=LLONG_MAX;
    vector<ll> fac;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            fac.pb(i);
            minfac=min(minfac,i);
            if(n/i!=i)
                fac.pb(n/i);
        }
    }
    if(minfac==LLONG_MAX){
        cout<<n;
    }
    else{
        ll ans=minfac;
        for(ll i=1;i<fac.size();i++){
            ans=__gcd(ans,fac[i]);
        }
        cout<<ans;
    }
	return  0;
}
