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

int32_t main(){
    sync;
    ll t;
    cin >> t;
    for (int i=0;i<t;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        ll ans=0;
        while(b>0 && c>1){
            b--;
            c--;
            c--;
            ans+=3;
        }
        while(a>0 && b>1){
            b--;
            b--;
            a--;
            ans+=3;
        }
        cout << ans << endl;
    }
}































