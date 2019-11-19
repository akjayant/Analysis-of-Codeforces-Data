#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int dh[] = {0, 1, 0, -1};
const int dw[] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, K;
    cin >> n >> m >> K;
    vector<int> h(K), w(K);
    vector< vector<int> > rows(n), cols(m);
    for (int i = 0; i < K; i++) {
        cin >> h[i] >> w[i];
        h[i]--;
        w[i]--;
        rows[h[i]].push_back(w[i]);
        cols[w[i]].push_back(h[i]);
    }

    for (int i = 0; i < n; i++) {
        rows[i].push_back(-1);
        rows[i].push_back(m);
        sort(rows[i].begin(), rows[i].end());
    }

    for (int i = 0; i < m; i++) {
        cols[i].push_back(-1);
        cols[i].push_back(n);
        sort(cols[i].begin(), cols[i].end());
    }   

    int ch = 0, cw = 0, dir = 0;
    int minh = 0, maxh = n, minw = -1, maxw = m;
    ll rest = (ll)n * m - K - 1;
    bool turned = false;
    while (rest > 0) {
        if (dir == 0) {
            int idx = *upper_bound(rows[ch].begin(), rows[ch].end(), cw);
            int nw = min(idx, maxw) - 1;
            if (nw == cw && turned) break;
            maxw = min(maxw, nw);
            rest -= abs(nw - cw);
            cw = nw;
            dir = 1;
            turned = true;
        } else if (dir == 1) {
            int idx = *upper_bound(cols[cw].begin(), cols[cw].end(), ch);
            int nh = min(idx, maxh) - 1;
            if (nh == ch && turned) break;
            maxh = min(maxh, nh);
            rest -= abs(nh - ch);
            ch = nh;
            dir = 2;
            turned = true;
        } else if (dir == 2) {
            int idx = *prev(lower_bound(rows[ch].begin(), rows[ch].end(), cw));
            int nw = max(idx, minw) + 1;
            if (nw == cw && turned) break;
            minw = max(minw, nw);
            rest -= abs(nw - cw);
            cw = nw;
            dir = 3;
            turned = true;
        } else {
            int idx = *prev(lower_bound(cols[cw].begin(), cols[cw].end(), ch));
            int nh = max(idx, minh) + 1;
            if (nh == ch && turned) break;
            minh = max(minh, nh);
            rest -= abs(nh - ch);
            ch = nh;
            dir = 0;
            turned = true;
        }
    }
    cout << (rest == 0 ? "Yes" : "No") << "\n";
    return 0;
}