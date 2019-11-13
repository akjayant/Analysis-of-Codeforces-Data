#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int inf = 1e9 + 7;
const int MAXN = 1e5 + 7;

main() {
    cout.precision(20);
    cout << fixed;
    long long n, m;
    cin >> n >> m;
    long long pows_2[100];
    pows_2[0] = 1;
    pows_2[1] = 2;
    for (int i = 2; i < 60; ++i) {
        pows_2[i] = (pows_2[i - 1] * pows_2[i - 1]) % inf;
    }
    long long c = 1;
    int pos = 1;
    while (m != 0) {
        if (m % 2 == 1) c = (c * pows_2[pos]) % inf;
        ++pos;
        m /= 2;
    }
    c = (c + inf - 1) % inf;
    long long pows_c[100];
    pows_c[0] = 1;
    pows_c[1] = c;
    for (int i = 2; i < 60; ++i) {
        pows_c[i] = (pows_c[i - 1] * pows_c[i - 1]) % inf;
    }
    long long ans = 1;
    pos = 1;
    while (n != 0) {
        if (n % 2 == 1) ans = (ans * pows_c[pos]) % inf;
        ++pos;
        n /= 2;
    }
    cout << ans;
    return 0;
}