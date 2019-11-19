#include <bits/stdc++.h>
using namespace std;
#define re return
#define ll long long
#define du double
#define co continue
#define gcd __gcd
#define br break
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fast();
    ll q,n;
    cin >> q;
    string s;
    ll ans=0;
    while(q--){
        cin >> n;
        cin >> s;
        ans=n;
        for (ll i=0;i<n;++i){
            if (s[i]=='1'){
                ans=max(ans,(i+1)*2);
                ans=max(ans,(n-i)*2);
            }
        }
        cout << ans << "\n";
    }
    re 0;
}
