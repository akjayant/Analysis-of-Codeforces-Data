#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int N = 2 * 1e5 + 10;
 
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll n, k, x;
    set<ll> s;
    map<ll, ll> mp;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> x;
        ++mp[x];
        s.insert(x);
    }
    while(k){
        ll v1 = *s.begin();
        ll v2 = *(--s.end());
        if(v1 == v2)    break;
        if(mp[v1] < mp[v2]){
            s.erase(s.begin());
            ll v3 = *s.begin();
            if((v3 - v1) * mp[v1] <= k){
                mp[v3] += mp[v1];
                k -= (v3 - v1) * mp[v1];
            }
            else{
                v1 += k / mp[v1];
                k = 0;
                s.insert(v1); 
            }
        }
        else{
            s.erase(--s.end());
            ll v3 = *(--s.end());
            if((v2 - v3) * mp[v2] <= k){
                mp[v3] += mp[v2];
                k -= (v2 - v3) * mp[v2];
            }
            else{
                v2 -= k / mp[v2];
                k = 0;
                s.insert(v2);
            }
        }
    }
    cout << *(--s.end()) - *s.begin() << "\n";
}