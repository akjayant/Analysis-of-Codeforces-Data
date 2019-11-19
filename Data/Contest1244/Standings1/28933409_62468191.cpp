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
const int N=1e3+100;
int32_t main(){
    sync;
    ll t;
    cin >> t;
    for (int i=0;i<t;i++){
        ll n;
        cin >> n;
        ll ans=n;
        string s;
        cin >> s;
        for (int j=0;j<n;j++){
            if (s[j]=='1'){
                ans=max(ans,2*j+2);
            }
        }
        reverse(s.begin(),s.end());
        for (int j=0;j<n;j++){
            if (s[j]=='1'){
                ans=max(ans,2*j+2);
            }
        }
        cout << ans << endl;
    }


}



















