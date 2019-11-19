#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 2 * 1e5 + 7;


main() {
    cout.precision(20);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> OW;
    vector<pair<int, int>> OB;
    int pos2 = 0;
    int pos1 = 0;
    int pos_finish = n;
    while (pos_finish > 1 && s[pos_finish - 1] == s[0]) --pos_finish;
    if (pos_finish == 1) {
        for (int i = 0; i < n; ++i) {
            cout << s[0];
        }
        return 0;
    }
    while (pos2 + 1 < pos_finish && s[pos2] == s[pos2 + 1]) ++pos2;
    if ((n - pos_finish) + pos2 + 1 > 1) {
        if (s[0] == 'W') OW.push_back({pos_finish % n, pos2});
        else OB.push_back({pos_finish % n, pos2});
    }
    pos1 = pos2 + 1;
    pos2++;
    while (pos1 < pos_finish) {
        while (pos2 + 1 < pos_finish && s[pos2 + 1] == s[pos2]) ++pos2;
        if (pos2 - pos1 + 1 > 1) {
            if (s[pos1] == 'W') OW.push_back({pos1, pos2});
            else OB.push_back({pos1, pos2});
        }
        pos2++;
        pos1 = pos2;
    }
    int type[MAXN];
    for (int i = 0; i < n; ++i) {
        type[i] = 0;
    }
    for (int i = 0; i < OW.size(); ++i) {
        for (int pos = OW[i].first; pos != OW[i].second; pos = (pos + 1) % n) {
            type[pos] = 1;
        }
        type[OW[i].second] = 1;
    }
    for (int i = 0; i < OB.size(); ++i) {
        for (int pos = OB[i].first; pos != OB[i].second; pos = (pos + 1) % n) {
            type[pos] = 2;
        }
        type[OB[i].second] = 2;
    }
    pair<int, int> left[MAXN];
    pair<int, int> right[MAXN];
    for (int i = 0; i < n; ++i) {
        left[i] = {-1, -1};
        right[i] = {-1, -1};
    }
    int pre = -1;
    for (int i = 0; i < 2 * n; ++i) {
        if (type[i % n] > 0) pre = i;
        if (pre != -1) left[i % n] = {type[pre % n], i - pre};
    }
    pre = -1;
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (type[i % n] > 0) pre = i;
        if (pre != -1) right[i % n] = {type[pre % n], pre - i};
    }
    for (int i = 0; i < n; ++i) {
        int mini_1 = inf;
        int mini_2 = inf;
        if (left[i].first != -1) mini_1 = left[i].second;
        if (right[i].first != -1) mini_2 = right[i].second;
        if (min(mini_1, mini_2) > k) {
            int cur_col = (s[i] == 'W');
            cur_col = (cur_col + k % 2) % 2;
            if (cur_col == 0) cout << 'B';
            else cout << 'W';
        } else {
            int tip  = 0;
            if (mini_1 < mini_2) tip = left[i].first;
            else tip = right[i].first;
            if (tip == 1) cout << 'W';
            else cout << 'B';
        }
    }
    return 0;
}