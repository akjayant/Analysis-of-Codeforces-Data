#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e6 + 10;
int T, n, a[maxn];
string s, t;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cin >> s >> t;
        vector<char> v1, v2;
        for (int i = 0; s[i]; ++i) {
            if (s[i] != t[i]) {
                v1.push_back(s[i]);
                v2.push_back(t[i]);
            }
        }
        if (v1.size() == 2 && v1[0] == v1[1] && v2[0] == v2[1]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}