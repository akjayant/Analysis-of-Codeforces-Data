#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
const ll mod=1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t-->0){
        ll x,n,m;
        cin>>n;

        ll o1=0,e1=0,o2=0,e2=0;
        for(ll i=0;i<n;i++){
            cin>>x;
            if(x&1)
                o1++;
            else
                e1++;
        }

        cin>>m;
        for(ll i=0;i<m;i++){
            cin>>x;
            if(x&1)
                o2++;
            else
                e2++;
        }

        ll ans = o1*o2 + e1*e2;
        cout<<ans<<"\n";

    }

}

