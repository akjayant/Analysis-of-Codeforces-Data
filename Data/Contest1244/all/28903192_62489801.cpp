#include <bits/stdc++.h>

#pragma GCC optimize("O3")

#define f first
#define s second
#define p push
#define pb push_back
#define ll long long
#define ld long double

using namespace std;

const ll N = 2e5 + 2, inf = 1e9 + 10;

ll a[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    ll k = 0;
    cin >> n >> k;
    for(ll i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    ll l = 0, r = n - 1;
    while(r - l > 0){
        while(l < n - 1 && a[l] == a[l + 1])
            ++l;
        while(r > 0 && a[r] == a[r - 1])
            --r;
        if(r - l <= 0)
            break;
        if(k < l + 1 && k < n - r)
            break;
        if(l + 1 < n - r){
            if(k > (a[l + 1] - a[l])*(l + 1))
                k -= (a[l + 1] - a[l])*(l + 1), ++l;
            else{
                a[l] += k / (l + 1);
                break;
            }
        }else{
            if(k > (a[r] - a[r - 1])*(n - r))
                k -= (a[r] - a[r - 1])*(n - r), --r;
            else{
                a[r] -= k / (n - r);
                break;
            }
        }
    }
    cout << a[r] - a[l];
}
