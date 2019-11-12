#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct wor {
    char a;
    int i;
    int s;
};

bool operator <(wor a, wor b) {
    return a.a < b.a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string g;
        cin >> g;
        int diff = 0;
        vector<int> f;
        vector<priority_queue<int>> cnt_a(26, priority_queue<int>());
        vector<priority_queue<int>> cnt_b(26, priority_queue<int>());
        for (int i = 0; i < n; i++) {
            if (s[i] != g[i]) {
                diff++;
                f.push_back(i);
            }
            cnt_a[s[i]-'a'].push(-i);
            cnt_b[g[i] - 'a'].push(-i);
        }
        bool ok = true;
        for (int i = 0; i < cnt_a.size(); i++) {
            if ((cnt_a[i].size() + cnt_b[i].size()) % 2 == 1) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "No" << endl;
        }
        else {
            vector<pair<int, int>> rot;
            for (int i = 0; i < n - 1; i++) {
                if (s[i] != g[i]) {
                    int d = -1;
                    for (int j = i + 1; j < n; j++) {
                        if (s[j] == s[i]) {
                            d = j;
                            break;
                        }
                    }
                    if (d != -1) {
                        char temp = g[i];
                        g[i] = s[d];
                        s[d] = temp;
                        rot.push_back({d, i});
                    }
                    else {
                        int b = -1;
                        for (int j = i + 1; j < n; j++) {
                            if (g[j] == s[i]) {
                                b = j;
                                break;
                            }
                        }
                        g[b] = s[n - 1];
                        s[n - 1] = g[i];
                        rot.push_back({n - 1, b});
                        rot.push_back({n - 1, i});
                    }
                }
            }
            cout << "Yes" << endl;
            cout << rot.size() << endl;
            for (auto e: rot) {
                cout << e.first + 1 << " " << e.second + 1 << endl;
            }
        }

    }
    return 0;
}