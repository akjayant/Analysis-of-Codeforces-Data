#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main() {
    int k;
    cin >> k;
    while(k--) {
        int n;
        bool ans = true;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int diff_count = 0;
        char a_diff = 0, b_diff = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] != t[i])  {
                diff_count++;
                if(a_diff == 0) {
                    a_diff = s[i];
                    b_diff = t[i];
                } else {
                    if(a_diff != s[i] || b_diff != t[i]) {
                        ans = false;
                        break;
                    }
                }
                if(diff_count > 2) {
                    ans = false;
                    break;
                }
            }
        }
        if(diff_count != 2 || !ans) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}