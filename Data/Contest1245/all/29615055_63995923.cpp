#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve(){
    int a, b;
    cin >> a >> b;
    if(__gcd(a, b) == 1){
        cout << "Finite\n";
    }
    else cout << "Infinite\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
