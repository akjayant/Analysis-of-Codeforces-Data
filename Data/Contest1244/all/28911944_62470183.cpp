#include <bits/stdc++.h>

#define pb push_back
#define debug(x) cout << #x << "  :  " << x


using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ind = -1;
        int ans1 = 0, ans2 =0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
                ind = max(ind, i);
        }
        if (ind == -1) {
            ans1 = n;
        }
        else {
            ans1 = max(n, 2 * (ind + 1));
        }
        ind = -1;
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == '1')
                ind = i;
        }
        if (ind == -1) {
            ans2 = n;
        }
        else {
            ans2 = max(n, 2 * ((n - 1-ind) + 1));
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}