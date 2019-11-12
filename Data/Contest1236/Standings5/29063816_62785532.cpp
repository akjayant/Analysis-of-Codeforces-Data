#include <bits/stdc++.h>
#define ll long long int
#define Zeroes ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Auto int main()
#define Accepted {return 0;}
int const Max = 1e5 + 7;
int const MOD = 1e9 + 7;

using namespace std;

ll t;

ll slove1(ll a, ll b,ll c) {
    ll ans = 0;
    while(a && b) {
        if(a < 1 || b < 2)
            break;
        ans += 3;
        a--;
        b -= 2;
    }
    while(b && c) {
        if(b < 1 || c < 2)
            break;
        ans += 3;
        b--;
        c -= 2;
    }
    return ans;
}

ll slove2(ll a, ll b,ll c) {
    ll ans = 0;

    while(b && c) {
        if(b < 1 || c < 2)
            break;
        ans += 3;
        b--;
        c -= 2;
    }
    while(a && b) {
        if(a < 1 || b < 2)
            break;
        ans += 3;
        a--;
        b -= 2;
    }
    return ans;
}

Auto {
    Zeroes
    cin >> t;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;

        cout << max(slove1(a,b,c), slove2(a,b,c)) << endl;
    }

    Accepted
}
