#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5 + 5;
ll n, k, a[N];
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin>>n>>k;
    for (ll i=1; i<=n; ++i) cin>>a[i];
    sort(a+1, a+1+n);

    ll i=1, j=n;
    while (i<j && k>0) {
        while (a[i]==a[i+1]) ++i;
        while (a[j]==a[j-1]) --j;
        if (i>=j) break;
        if (i <= n-j+1) {
            ll num=min(k/i, a[i+1]-a[i]);
            if (num==0) break;
            a[i]+=num; k-=num*i;
        } else {
            ll num=min(k/(n-j+1), a[j]-a[j-1]);
            if (num==0) break;
            a[j]-=num; k-=num*(n-j+1);
        }
    }

    cout<<(a[j]-a[i]);
    return 0;
}