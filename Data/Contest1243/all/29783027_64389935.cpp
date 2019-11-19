#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        string g;
//        cin >> g;
//        int diff = 0;
//        vector<int> f;
//        vector<queue<int>> cnt_a(26, 0);
//        vector<queue<int>> cnt_b(26, 0);
//        for (int i = 0; i < n; i++) {
//            if (s[i] != g[i]) {
//                diff++;
//                f.push_back(i);
//            }
//            cnt_a[s[i]-'a'].push(i);
//            cnt_b[g[i] - 'a'].push(i)
//        }
//        bool ok = true;
//        for (int i = 0; i < cnt_a.size(); i++) {
//            if ((cnt_a[i].size() + cnt_b[i].size()) % 2 == 1) {
//                ok = false;
//            }
//        }
//        if (!ok) {
//            cout << "No" << endl;
//        }
//        else {
//            for (int i = 0; i < n; i++) {
//
//            }
//        }
//    }
    long long t;
    cin >> t;
    if (t == 1) {
        cout << 1;
        return 0;
    }
    map<long long, int> m;
    for (long long i = 2; i * i <= t; i++) {
        while (t % i == 0) {
            m[i]++;
            t /= i;
        }
    }
    if (t > 1) {
        m[t]++;
    }
    if (m.size() > 1) {
        cout << 1;
    }
    else {
        cout << m.begin() -> first;
    }
    return 0;
}