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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll a = 1e18, b = 1e18;
        for(long long i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                continue;
            }
            a = min(a, i);
            b = min(b, n - i - 1);
        }
        ll c = min(a, b);
        if(c > 1e9)
        {
            cout << n << endl;
        }
        else
        cout << 2 * (n - c) << endl;
    }
}
