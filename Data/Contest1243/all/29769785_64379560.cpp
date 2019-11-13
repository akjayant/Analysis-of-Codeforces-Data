#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, i, n;
    string s, t;
    vector<int> diff;

    cin >> k;
    while(k--) {
        cin >> n;
        cin >> s >> t;
        diff.clear();
        for(i = 0; i < n; i++) {
            if(s[i] != t[i])
                diff.push_back(i);
        }
        
        if(diff.size() == 0 || (diff.size() == 2 && s[diff[0]] == s[diff[1]] && t[diff[0]] == t[diff[1]])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
