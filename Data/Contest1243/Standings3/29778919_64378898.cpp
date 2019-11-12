#include <bits/stdc++.h>
using namespace std;

int n;
char s1[100005], s2[100005];

void solve() {
    scanf("%d", &n);
    scanf(" %s", s1);
    scanf(" %s", s2);
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            diff.push_back(i);
        }
    }

    if (diff.size() == 0) {
        printf("YES\n");
    } else if (diff.size() == 2) {
        if (s1[diff[0]] == s1[diff[1]] && s2[diff[0]] == s2[diff[1]]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}