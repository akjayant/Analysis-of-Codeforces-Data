#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;
typedef long long ll;

set <ll> ms;

void fact(ll x){
    for (ll i = 2; i * i <= x; i++){
        while (x % i == 0){
            x /= i;
            ms.insert(i);
        }
    }
    if (x != 1) ms.insert(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    if (n == 1){
        cout << 1;
        return 0;
    }
    fact(n);
    if (ms.size() > 1){
        cout << 1;
        return 0;
    }
    cout << *ms.begin();
    return 0;
}
