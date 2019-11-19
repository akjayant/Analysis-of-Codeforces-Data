#include <bits/stdc++.h>
#define ll long long
#define lf long double
#define INF 1000000000
#define MAX 1000001
#define M 1000000007
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    ll s1 = 0, s2 = 0;
    for (ll i=0;i<n/2;i++) s1+=a[i];
    for (ll i=n/2;i<n;i++) s2+=a[i];
    cout << s1*s1 + s2*s2 << endl;
    return 0;
}