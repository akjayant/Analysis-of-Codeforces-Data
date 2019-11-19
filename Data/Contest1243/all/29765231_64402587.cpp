#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin>>n;
    vector<ll> pf;
    for(ll d = 2; d*d<=n; d++) {
        if(n%d==0) {
            pf.emplace_back(d);
            while(n%d == 0) n/=d;
        }
    }
    if(n != 1) pf.emplace_back(n);

    if(size(pf) == 1) cout << pf[0] << "\n";
    else cout << 1 << "\n";
}