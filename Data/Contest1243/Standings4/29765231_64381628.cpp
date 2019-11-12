#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--) {
        int n;
        cin>>n;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int ct = count_if(begin(a), end(a), [i](int x) {
                return x >= i;
            });
            if(ct >= i) ans = i;
        }
        cout<<ans<<"\n";
    }
}