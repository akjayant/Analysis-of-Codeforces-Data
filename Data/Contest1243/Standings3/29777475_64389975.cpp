#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5 + 5;
 
#define dbg(a) cout << "-> " << __LINE__ << ": " << #a << " = " << a << endl
 
int main() {
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        int n;
        scanf("%d", &n);
        string s, t;
        cin >> s >> t;
        vector<int> dif;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                dif.push_back(i);
            }
        }
        if (dif.empty()) {
            puts("Yes");
            continue;
        }
        if ((int) dif.size() == 2) {
            if (s[dif[0]] == s[dif[1]] and t[dif[0]] == t[dif[1]]) {
                puts("Yes");
            }
            else {
                puts("No");
            }
        }
        else {
            puts("No");
        }
    }
    return 0;
}
