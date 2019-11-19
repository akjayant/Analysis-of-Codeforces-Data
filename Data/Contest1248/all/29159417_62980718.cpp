#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll modpow(ll a, ll b){

    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}



int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<ll> inp;

    for(int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        inp.push_back(x);
    }

    sort(inp.rbegin(), inp.rend());

    int n1 = (n+1)/2;

    ll sm1 = 0;
    ll sm2 = 0;

    for(int i = 0; i < n1; i++) {
        sm1 += inp[i];
    }

    for(int i = n1; i < n; i++) {
        sm2 += inp[i];
    }

    ll ans = sm1*sm1 + sm2*sm2;

    cout<<ans<<endl;




}
