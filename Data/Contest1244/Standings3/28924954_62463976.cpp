#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll t;
    cin >> t;
    for(int e = 0; e < t; e++)
    {
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        ll x = (a + c - 1) / c;
        ll y = (b + d - 1) / d;
        if(x + y > k)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << x << ' ' << y << endl;
        }
    }
}
