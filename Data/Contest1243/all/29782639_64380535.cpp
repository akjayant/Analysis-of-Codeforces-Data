#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int T, n;
char s[maxn], t[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s %s", &n, s + 1, t + 1);
        vector<pair<int, int>> V;
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] ^ t[i]) {
                bool tmp = 0;
                for (int j = i + 1; j <= n; j++) {
                    if (t[i] == t[j]) {
                        V.push_back(make_pair(i, j));
                        swap(s[i], t[j]);
                        tmp = 1; break;
                    } else if (t[i] == s[j]) {
                        V.push_back(make_pair(j, j));
                        swap(s[j], t[j]);
                        V.push_back(make_pair(i, j));
                        swap(s[i], t[j]);
                        tmp = 1; break;
                    }
                }
                if (!tmp) { flag = 1; break; }
            }
        }
        if (flag) { printf("No\n"); continue; }
        printf("Yes\n%d\n", V.size());
        for (auto p : V) {
            printf("%d %d\n", p.first, p.second);
        }
    }
    return 0;
}