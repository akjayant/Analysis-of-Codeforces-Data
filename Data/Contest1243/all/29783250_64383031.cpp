//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];

vector<ll> v;

void solve(){
    ll n;
    string s, ss;
    cin >> n >> s >> ss;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] != ss[i]){
            v.push_back(i);
        }
    }
    if(s == ss) cout << "YES\n";
    else if(v.size() == 2){
        if(s[v[0]] == s[v[1]] and ss[v[1]] == ss[v[0]]) cout << "YES\n";
        else    cout << "NO\n";
    }
    else    cout << "NO\n";
    v.clear();
}
 
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
// nEro