#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 7;

ll n, k;
map<ll, ll> m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        m[x]++;
    }
    while(true) {
        if(m.size() == 0) {
            cout<<0;
            return 0;
        }
        auto it = m.begin();
        ll val = it->first, cnt = it->second;
        auto it2 = m.rbegin();
        ll val2 = it2->first, cnt2 = it2->second;
        //cout<<val<<" "<<cnt<<" "<<val2<<" "<<cnt2<<":"<<endl;
        if( cnt <= cnt2) {
            it++;
            ll nxtval = it->first;
            if( (nxtval - val ) * 1ll * cnt <= k) {
                k -= (nxtval - val ) * 1ll * cnt;
                m[nxtval] += cnt;
                m.erase(val);
            }
            else {
                ll newval = 1ll * (k / cnt) + val;
                m.erase(val);
                m[newval] = cnt;
                break;
            }
            continue;
        }
        it2++;
        ll nxtval = it2->first;
        if( (val2 - nxtval ) * 1ll * cnt2 <= k) {
            k -= (val2 - nxtval ) * 1ll * cnt2;
            m[nxtval] += cnt2;
            m.erase(val2);
        }
        else {
            ll newval = val2 - 1ll * (k / cnt2);
            m.erase(val2);
            m[newval] = cnt2;
            break;
        }
        continue;
    }
    auto it = m.begin();
    auto it2 = m.rbegin();
    cout<<it2->first - it->first;
}
