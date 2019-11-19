#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        char s[n+1]; for (int i=1; i<=n; ++i) cin>>s[i];
        int res = n;
        for (int i=1; i<=n; ++i) if (s[i] == '1') res = max({res, 2*i, 2*(n-i+1)});
        cout<<res<<"\n";
    }
    return 0;
}