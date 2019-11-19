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

    ll t;
    
    cin>>t;

    while(t--){
        ll n,m;
        
        ll e1 = 0, e2=0;

        cin>>n;
        ll temp = 0;
        for(ll i=0;i<n;i++){
            

            cin>>temp;

            if(temp%2==1){
                e1++;
            }
        }

        cin>>m;

        for(ll i=0;i<m;i++){
            

            cin>>temp;

            if(temp%2==1){
                e2++;
            }
        }

        ll ans = e1*e2 + (n-e1)*(m-e2);

        cout<<ans<<"\n";
    }
}