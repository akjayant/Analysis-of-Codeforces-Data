#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
#define ll long long 
#define N 100005
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define piii pair<int, pii>
#define print(x) cout << #x << "=" << x << "\t";
#define endl "\n"
#define newline cout << endl;

int n;
int m;

ll power(ll a, ll n) {
    if (a == 0) return 0;
    if (a == 1) return 1;
    if (n == 0) return 1;
    if (n == 1) return a;
    ll t = power(a, n/2);
    return t * t % mod * (n % 2 == 1 ? a : 1) % mod;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    cin >> n >> m;
    cout << power((power(2, m) - 1 + mod) % mod, n);
    return 0;
}
