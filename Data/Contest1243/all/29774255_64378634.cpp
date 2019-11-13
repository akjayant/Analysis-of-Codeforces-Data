#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    for (int e = 0; e < k; e++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int one = -1, two = -1;
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (one == -1) {
                    one = i;
                } else if (two == -1) {
                    two = i;
                } else {
                    f = false;
                    break;
                }
            }
        }
        if (!f || one == -1 || two == -1) {
            cout << "No";
        } else {
            if (s[one] == s[two] && t[one] == t[two]) {
                cout << "Yes";
            } else {
                cout << "No";
            }
        }
        cout << "\n";
    }


    return 0;
}

