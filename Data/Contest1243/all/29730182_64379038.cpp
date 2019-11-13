#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N= 1e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

int main(){
    ll t;
    cin>>t;

    while(t-->0){
        ll n;
        cin>>n;

        ll arr[n];
        for(ll i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);

        ll ans = 0;
        for(ll side=n;side>0;side--){
            if(arr[n-side]>=side){
                ans = side;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}

