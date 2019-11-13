#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        char s[10001], t[10001];
        cin >> s >> t;

        int cnt = 0;
        vector<int> diff_idx;
        for(int i=0; i<n; i++)
            if(s[i] != t[i]) diff_idx.push_back(i);

        // cout << diff_idx.size() << '\n';

        if(diff_idx.size() != 2) {
            cout << "No\n";
            continue;
        }

        int a = diff_idx[0], b = diff_idx[1];
        if(s[a] == s[b] && t[a] == t[b] && s[a] != t[a]) {
            cout << "Yes\n";
            continue;
        }

        cout << "No\n";
    }
    return 0;
}