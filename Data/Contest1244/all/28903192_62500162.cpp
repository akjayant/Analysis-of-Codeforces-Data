#include <bits/stdc++.h>

#pragma GCC optimize("O3")

#define f first
#define s second
#define p push
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

const ll N = 2e5 + 5, inf = 1e18 + 10;

ll f[N], db[N], df[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i){
        db[i] = inf;
        df[i] = inf;
    }
    for(ll i = 0; i < n; ++i){
        if(s[i] == s[(i + 1) % n]){
            f[i] = 1, f[(i + 1) % n] = 1;
            db[i] = 0, db[(i + 1) % n] = 0;
            df[i] = 0, df[(i + 1) % n] = 0;
        }
    }
    for(ll i = 0; i < n; ++i)
        db[i] = min(db[i], db[(i - 1 + n) % n] + 1);
    for(ll i = 0; i < n; ++i)
        db[i] = min(db[i], db[(i - 1 + n) % n] + 1);
    for(ll i = n - 1; i >= 0; --i)
        df[i] = min(df[i], df[(i + 1 + n) % n] + 1);
    for(ll i = n - 1; i >= 0; --i)
        df[i] = min(df[i], df[(i + 1 + n) % n] + 1);
    for(ll i = 0; i < n; ++i){
        if(db[i] < df[i] && db[i] <= k)
            s[i] = s[(i - db[i] + n) % n], f[i] = 1;
        else if(df[i] <= k)
            s[i] = s[(i + df[i] + n) % n], f[i] = 1;
    }
    for(ll i = 0; i < n; ++i){
        if(f[i])
            cout << s[i];
        else{
            if(k % 2){
                if(s[i] == 'W')
                    cout << 'B';
                else
                    cout << 'W';
            }else
                cout << s[i];
        }
    }
}
