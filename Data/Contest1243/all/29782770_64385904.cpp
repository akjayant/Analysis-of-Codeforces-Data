#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector< int > fail;
        for(int j = 0; j < n; j++) {
            if(s[j] == t[j]) continue;
            fail.push_back(j);
        }

        //for(int j = 0; j <fail.size(); j++) cout << fail[j] << " ";
        //cout << endl;

        if(fail.size() > 2 || fail.size() == 1) {
            cout << "NO" << endl;
            continue;
        }

        if(fail.size() == 2) {
            if(s[fail[0]] == s[fail[1]] && t[fail[1]] == t[fail[0]]) {
                cout << "YES" << endl;
                continue;
            } else {
                cout << "NO" << endl;
                continue;
            }
        }

        cout << "YES" << endl;
    }
    return 0;
}
