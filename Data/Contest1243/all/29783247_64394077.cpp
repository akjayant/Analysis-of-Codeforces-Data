#include <bits/stdc++.h>
using namespace std;

long long gcd( long long a, long long b ) {
    return b? gcd(b, a%b) : a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin >> n;
    if( n == 1 ) {
        cout << 1 << '\n';
        return 0;
    }
    vector< long long > v;
    for( long long i = 2; i*i <= n; i++ ) {
        if( n%i == 0 ) {
            v.emplace_back(i);
            while( n%i == 0 ) {
                n /= i;
            }
        }
    }
    if( n != 1 ) v.emplace_back( n );
    long long ans = 0;
    for( long long &i: v ) {
        ans = gcd(ans, i);
    }
    cout << ans << '\n';
    return 0;
}