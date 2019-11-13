#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=2e5+10;

int n,a[N];

int main() {
    ios::sync_with_stdio(0);
    int k; cin>>k;
    while (k--) {
        cin>>n; for (int i=1; i<=n; ++i) cin>>a[i];
        sort(a+1, a+n+1);
        int ans=1;
        for (int i=1;i<=n;++i)
            ans=max(ans,min(n-i+1, a[i]));
        cout<<ans<<endl;
    }
    return 0;
}