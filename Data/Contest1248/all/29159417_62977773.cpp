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

    int t;
    cin>>t;

    while(t--) {
        int n,m;
        cin>>n;

        ll cnt1 = 0;
        ll cnt2 = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin>>x;

            if(x % 2) cnt1++;
            else cnt2++;
        }

        cin>>m;
        ll cnt3 = 0;
        ll cnt4 = 0;

        for(int i = 0; i < m; i++) {
            int x;
            cin>>x;

            if(x % 2) cnt3++;
            else cnt4++;
        }

        ll ans = 0;

        ans = cnt1*cnt3 + cnt2*cnt4;

        cout<<ans<<endl;




    }


}
