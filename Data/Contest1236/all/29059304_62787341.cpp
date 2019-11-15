#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m;
long long ans;
long long f (long long x, long long y){
    if (y == 0) return 1;
    if (y % 2) return (f (x, y - 1) * x) % mod;
    long long b = f (x, y / 2);
    return b * b % mod;
}
int main(){


    cin >> n >> m;
    ans = f (f (2, m) - 1, n);
    cout << ans;
}
