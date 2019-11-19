#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, p, w, d, k1 = -1, k2, k3;
    cin>>n>>p>>w>>d;
    if(p % w == 0) {
        if(p / w <= n) {
            cout<<p/w<<" 0 "<<n-p/w;
        }
        else {
            cout<<-1;
        }
        return 0;
    }
    if(p < d) {
        if(p == 0) {
            cout<<0<<" "<<0<<" "<<n;
            return 0;
        }
        cout<<-1;
        return 0;
    }
    if(p % d == 0) {
        k1 = 0;
        k2 = p / d;
    }
    else {
        for(int i=1;i<=d;i++) {
            p -= w;
            if(p < d) {
                cout<<-1;
                return 0;
            }
            if(p % d == 0) {
                k1 = i;
                k2 = p / d;
                break;
            }
        }
    }
    if(k1 == -1) {
        cout<<-1;
        return 0;
    }
    ll nok = 1ll * w * d / __gcd(w, d);
    ll addx = 1ll * min((p / nok), k2/w) * d, miny = 1ll * min((p / nok), k2/w) * w;
    k1 += addx;
    k2 -= miny;
    if(k1 + k2 > n) {
        cout<<-1;
        return 0;
    }
    cout<<k1<<" "<<k2<<" "<<n-k1-k2;
}
