#include <bits/stdc++.h>
using namespace std;

int n;
char s1[100005], s2[100005];

void solve() {
    set<int> cp[2][40];
    scanf("%d", &n);
    scanf(" %s", s1);
    scanf(" %s", s2);
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        cp[0][s1[i] - 'a'].insert(i);
        cp[1][s2[i] - 'a'].insert(i);
    }

    bool bisa = true;
    for (char cc = 'a'; cc <= 'z'; cc++) {
        if ((cp[0][cc - 'a'].size() + cp[1][cc - 'a'].size()) % 2 == 1) {
            bisa = false;
        }
    }

    if (bisa) {
        printf("Yes\n");
        vector<pair<int, int> > pending;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s2[i] == s1[i]) {
                cp[0][s1[i] - 'a'].erase(i);
                cp[1][s2[i] - 'a'].erase(i);
                continue;
            }
            cnt++;
            char tr = s1[i];
            if (cp[0][tr - 'a'].size() == 1) {
                int pos1 = i + 1;
                int pos2 = *cp[1][tr - 'a'].begin();
                pending.push_back(make_pair(pos1 + 1, pos2 + 1));
                cp[0][tr - 'a'].insert(pos1); cp[0][s1[pos1] - 'a'].erase(pos1);
                cp[1][tr - 'a'].erase(pos2); cp[1][s1[pos1] - 'a'].insert(pos2);
                s2[pos2] = s1[pos1];
                s1[pos1] = tr;
                // printf("%d: %s %s\n", i, s1, s2);
            }

            int pos1 = *(cp[0][tr - 'a'].rbegin());
            int pos2 = i;
            pending.push_back(make_pair(pos1 + 1, pos2 + 1));
            cp[0][tr - 'a'].erase(pos1); cp[0][s2[pos2] - 'a'].insert(pos1);
            cp[1][tr - 'a'].insert(pos2); cp[1][s2[pos2] - 'a'].erase(pos2);
            s1[pos1] = s2[pos2];
            s2[pos2] = tr;

            cp[0][tr - 'a'].erase(i);
            cp[1][tr - 'a'].erase(i);

            // printf("%d: %s %s\n", i, s1, s2);
        }
        if (cnt == 0) {
            pending.push_back(make_pair(1, 1));
        }

        printf("%d\n", pending.size());
        for (const pair<int, int>& p : pending) {
            printf("%d %d\n", p.first, p.second);
        }
    } else {
        printf("No\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}
