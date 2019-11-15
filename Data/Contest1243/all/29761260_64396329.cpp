#include <bits/stdc++.h>

using namespace std;

int flag = 0;
vector<pair<int, int>> swaps;

void pushSwap(int i, int j) {
    if (flag == 0) {
        swaps.push_back(pair<int, int>(i, j));
    } else {
        swaps.push_back(pair<int, int>(j, i));
    }
}

int main() {
    int tests;
    char mas[26];
    cin >> tests;
    swaps.resize(100, pair<int, int>(0, 0));
    for (int test = 0; test<tests; test++) {
        int n;
        cin >> n;
        string s1, s2, tmp;
        cin >> s1 >> s2;
        swaps.clear();
        flag = 0;

        for (int i = 0; i < 26; i++)
            mas[i] = 0;

        for (auto c : s1)
            mas[c - 'a']++;

        for (auto c : s2)
            mas[c - 'a']++;

        char isError = 0;
        for (int i = 0; i < 26; i++) {
            if (mas[i] & 1) {
                isError = 1;
                break;
            }
        }

        if (isError) {
            cout << "NO" << endl;
            continue;
        }

        int cur = 0;

        while (cur < n) {
            if (s1[cur] == s2[cur]) {
                cur++;
                continue;
            }

            int i = cur + 1;
            while (i < n) {
                if (s1[i] == s1[cur])
                    break;
                i++;
            }

            if (i < n) {
                pushSwap(i, cur);
                char buf;
                buf = s2[cur];
                s2[cur] = s1[i];
                s1[i] = buf;
                cur++;
                continue;
            }

            char buf = s1[cur];
            s1[cur] = s2[cur];
            s2[cur] = buf;

            tmp = s1;
            s1 = s2;
            s2 = tmp;
            flag = !flag;
            pushSwap(cur, cur);
        }

        cout << "YES" << endl;
        cout << swaps.size() << endl;
        for (auto swap : swaps) {
            cout << swap.first + 1 << " " << swap.second + 1 << endl;
        }
    }
}