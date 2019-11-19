#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    ll x = p / w;
    for(long long i = x; i >= max(0LL, x - w); i--)
    {
        ll ost = p - i * w;
        if(ost % d == 0)
        {
            if(i + ost / d <= n)
            {
                cout << i << ' ' << ost / d << ' ' << n - (i + ost / d) << endl;
                return 0;
            }
        }
    }
    cout << -1;
}
