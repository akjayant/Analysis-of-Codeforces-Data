#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int M = 200010;


int main() {

    ios_base::sync_with_stdio(false);

    int t;
    cin>>t;
    while (t--) {
        int n;
        string s;

        cin>>n>>s;
        int ans = n;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ans = max(ans, (int)(2*(s.size()-i)));
                break;
            }
        }
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '1') {
                ans = max(ans, 2*(i+1));
                break;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}

