#include <bits/stdc++.h>
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
using namespace std;
 
typedef long long ll;

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    fastio

    ll n;
    cin >> n;

    vector<ll> a(n);

    for(ll i=0;i<n;i++) cin >> a[i];

    sort(a.begin(), a.end());
    ll x = 0, y = 0;

    for(ll i=0;i<n/2;i++){
        x += a[n-i-1];
        y += a[i];
    }

    if(n%2) x += a[n/2];
    cout << x*x+y*y;

    return 0;
}