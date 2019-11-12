#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int T, n;
char s[maxn], t[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s %s", &n, s + 1, t + 1);
        vector<pair<char, char>> V;
        for (int i = 1; i <= n; i++) {
            if (s[i] ^ t[i]) V.push_back(make_pair(s[i], t[i]));
        }
        if (V.size() == 0) {
            printf("Yes\n");
        } else if (V.size() != 2) {
            printf("No\n");
        } else {
            if (V[0].first == V[1].first && V[0].second == V[1].second) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
// ab, ba
// ab, ab