#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define F first
#define S second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll P(ll x,ll y){
    ll ret = 1;
    while(y){
        if(y%2)ret = (ret*x)%mod;
        x = (x*x)%mod;
        y/=2;
        
    }
    return ret;
}

int main(){
	FIO
    ll n;
    cin >> n;
    
    ll st = 1,fl = 1;
    vector<ll> v[n+1];
    for(ll i = 1;i<=n;i++){

        ll cnt = 1;
        if(fl){
            for(ll i = st;i<(st+n);i++){
                v[cnt++].push_back(i);
            }
        }
        else {
            for(ll i = (st+n-1);i>=st;i--){
                v[cnt++].push_back(i);
            }
        }
        fl^=1;
        st+=n;
    }
    for(ll i = 1;i<=n;i++){
        for(auto j:v[i]){
            cout << j << " ";
        }
        cout << endl;
    }
    
	return 0;
}





