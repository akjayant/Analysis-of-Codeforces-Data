#include <bits/stdc++.h>
using namespace std;
using ll = long long;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    if(n==1) {
        cout << 1 << "\n";
        return 0;
    }

    vector<ll> div;
    for(ll i=2;i*i<=n;i++) {
        int cnt=0;
        while(n%i==0) {
            n/=i;
            cnt++;
        }


        if(cnt) div.push_back(i);
    }

    if(n!=1) {
        div.push_back(n);
    }

    ll g = div[0];
    for(int i=1;i<div.size();i++) {
        g = __gcd(g,div[i]);
    }

    cout << g << "\n";


    return 0;
}