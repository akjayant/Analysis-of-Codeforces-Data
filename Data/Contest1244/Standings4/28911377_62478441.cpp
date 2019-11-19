#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 1e6+10;

string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cin >> s;
        int ans = n;
        int mmin = n; int mmax = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                mmin = min(mmin, i);
                mmax = max(mmax, i);
            }
        }
        int ans1 = 2*(mmax+1);
        int ans2 = 2*(n-mmin);
        ans = max(ans, ans1);
        ans = max(ans, ans2);
        cout << ans << endl;

    }

    return 0;
}