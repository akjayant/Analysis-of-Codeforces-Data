#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int f(const string &S) {
    int cnt = 0;
    for (auto c : S) if (c == '(') cnt++;
    if (cnt + cnt != S.size()) {
        return 0;
    }
    int level = 0;
    int minlevel = 0;
    for (auto c : S) {
        if (c == '(') level++;
        if (c == ')') level--;
        minlevel = min(minlevel, level);
    }
    int ans = 0;
    for (auto c : S) {
        if (c == '(') level++;
        if (c == ')') level--;
        if (level == minlevel) ans++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    int ans = 0, l = 1, r = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            swap(S[i], S[j]);
            auto val = f(S);
            if (val > ans) {
                l = i + 1, r = j + 1;
                ans = val;
            }
            swap(S[i], S[j]);
        }
    }
    cout << ans << '\n';
    cout << l << ' ' << r << '\n';
    return 0;
}