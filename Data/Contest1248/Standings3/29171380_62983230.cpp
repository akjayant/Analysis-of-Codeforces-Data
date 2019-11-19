#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
using namespace std;
 
const ll inf = 1e17;
const ll N = 1e6+10;
const ll bits = 30;
const ll mod = 1e9+7;

int main(){
    FASTIO;

    ll n;

    cin>>n;

    vector<ll>arr(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    sort(arr.begin(),arr.end());

    
    ll sum2=0;

    ll number = n/2;


    for(int i=0;i<number;i++){
        sum2+=arr[i];
    }

    // cout<<sum2<<" "<<number<<"\n";

    ll ans = sum2*sum2 + (sum-sum2)*(sum-sum2);

    cout<<ans<<"\n";


}