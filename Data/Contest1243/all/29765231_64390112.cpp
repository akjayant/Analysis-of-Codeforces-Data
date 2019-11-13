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
        string s, t;
        cin>>s>>t;
        vi diffs;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                diffs.emplace_back(i);
            }
        }
        bool ans = false;
        if(size(diffs) == 0) {
            ans = true;
        }
        if(size(diffs) == 2) {
            int x = diffs[0], y = diffs[1];
            if(s[x] == s[y] && t[x] == t[y]) {
                ans = true;
            }
        }
        cout<<(ans?"Yes":"No")<<"\n";
    }
}
