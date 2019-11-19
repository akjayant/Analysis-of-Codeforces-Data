typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll n;
    std::cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll x = 0;
    ll y = 0;
    for (int i = 0; i < n/2; i++) {
        x += a[i];
    }
    for (int i = n/2; i < n; i++) {
        y += a[i];
    }
    std::cout << x*x+y*y << std::endl;
}
