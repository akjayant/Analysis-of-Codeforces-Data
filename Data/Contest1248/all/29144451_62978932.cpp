#include <bits/stdc++.h>
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
 
typedef long long ll;

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fastio

    ll t;
    cin >> t;

    while(t--){
        ll odd1 = 0, even1 = 0, odd2 = 0, even2 = 0;
        ll n;
        cin >> n;
        vector<ll> p(n);
        for(ll i=0;i<n;i++){
            cin >> p[i];
            if(p[i]%2) odd1++;
            else even1++;
        }
        ll m;
        cin >> m;
        vector<ll> q(m);
        for(ll i=0;i<m;i++){
            cin >> q[i];
            if(q[i]%2) odd2++;
            else even2++;
        }

        cout << even1*even2+odd1*odd2 << endl;
    }

    return 0;
}