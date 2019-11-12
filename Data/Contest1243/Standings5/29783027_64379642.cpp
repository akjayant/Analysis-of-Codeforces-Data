#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string g;
        cin >> g;
        int diff = 0;
        vector<int> f;
        vector<int> cnt_a(26, 0);
        vector<int > cnt_b(26, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] != g[i]) {
                diff++;
                f.push_back(i);
            }
            cnt_a[s[i]-'a']++;
            cnt_b[g[i] - 'a']++;
        }
        if (diff > 2 or diff == 1) {
            cout << "No";
        }
        else if (diff == 2) {
            if (s[f[1]] == s[f[0]] && g[f[0]] == g[f[1]]) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
        }
        else if (diff == 0) {
            bool ok = false;
            for (int i = 0; i < 26; i++) {
                if (cnt_a[i] > 0 && cnt_b[i] > 0) {
                    ok = true;
                }
            }
            if (ok) {
                cout << "Yes";
            }
            else {
                cout << "No";
            }
        }
        cout << endl;
    }
    return 0;
}