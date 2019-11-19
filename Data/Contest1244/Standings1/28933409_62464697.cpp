#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int N=1e5+100;
ld par[N];
ld a[N];
ld s[N];
int32_t main(){
    sync;
    ll t;
    cin >> t;
    for (int i=0;i<t;i++){
        ll a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        ll z=(a+c-1)/c;
        ll e=(b+d-1)/d;
        if (z+e>k){
            cout << -1 << endl;
            continue;
        }
        cout << z << " " << e << endl;
    }

}



















