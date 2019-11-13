//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N], h[30];

vector<pair<ll, ll> > vp;

void solve(){
    ll n;
    string s, ss;
    cin >> n >> s >> ss;
    for(int i = 0; i < n; ++i){
        ++h[s[i] - 'a'];
        ++h[ss[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i){
        if(h[i] & 1){
            cout << "NO\n";
            return;
        }
    }
    for(int i = 0; i < n; ++i){
        if(s[i] != ss[i]){
            ll fl = 0;
            for(int j = i + 1; j < n; ++j){
                if(s[i] == s[j]){
                    vp.push_back({j + 1, i + 1});
                    swap(ss[i], s[j]);
                    fl = 1;
                    break;
                }
            }
            if(fl)  continue;
            for(int j = i + 1; j < n; ++j){
                if(s[i] == ss[j]){
                    vp.push_back({n, j + 1});
                    swap(ss[j], s[n - 1]);
                    vp.push_back({n, i + 1});
                    swap(s[n - 1], ss[i]);
                    break;
                }
            }
        }
    }
    cout << "YES\n" << vp.size() << "\n";
    for(auto i: vp) cout << i.first << " " << i.second << "\n";
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
        memset(h, 0, sizeof h);
        vp.clear();
    }
}
// nEro