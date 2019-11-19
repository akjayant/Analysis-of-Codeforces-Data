#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pll pair<ll, ll>

#define MOD 1000000007

struct EVT{
    int type;
    int a;
    int b;
    ll score;
};

int head(vector<int>& comp, int v) {
    int t = v, tmp;
    while (t != comp[t]) {
        t = comp[t];
    }
    while (v != t) {
        tmp = comp[v];
        comp[v] = t;
        v = tmp;
    }
    return t;
}

bool merge(vector<int>& comp, int v, int u) {
    v = head(comp, v);
    u = head(comp, u);
    if (v != u) {
        comp[v] = u;
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    vector<ll> c(n), k(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<EVT> events(n + n * (n-1) / 2);
    for (int i = 0; i < n; i++) {
        events[i].type = 0;
        events[i].a = i;
        events[i].b = 0;
        events[i].score = c[i];
    }
    int pos = n;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            events[pos].type = 1;
            events[pos].a = i;
            events[pos].b = j;
            events[pos].score = (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) * (k[i] + k[j]);
            pos++;
        }
    }
    sort(events.begin(), events.end(), [&](EVT& l, EVT& r) {
        return l.score < r.score;
    });

    vector<bool> vkl(n, false);
    vector<int> comp(n);
    for (int i = 0; i < n; i++) {
        comp[i] = i;
    }

    vector<int> res_v;
    vector<pair<int, int>> res_e;

    ll cost = 0;
    for (auto& evt: events) {
        if (evt.type == 0) {
            if (!vkl[evt.a]) {
                int vv = head(comp, evt.a);
                for (int i = 0; i < n; i++) {
                    if (vv == head(comp, i)) {
                        vkl[i] = true;
                    }
                }
                cost += evt.score;
                res_v.emplace_back(evt.a);
                //cout << "test " << evt.a << " " << evt.score << "\n";
            }
        } else {
            if (vkl[evt.a] && vkl[evt.b]) {
                continue;
            }

            if (!merge(comp, evt.a, evt.b)) {
                continue;
            }

            cost += evt.score;
            res_e.emplace_back(evt.a, evt.b);
            if (!vkl[evt.a] && !vkl[evt.b]) {
                continue;
            }

            int vv = head(comp, evt.a);
            for (int i = 0; i < n; i++) {
                if (vv == head(comp, i)) {
                    vkl[i] = true;
                }
            }
        }
    }


    cout << cost << "\n";
    cout << res_v.size() << "\n";
    if (!res_v.empty()) {
        for (auto& x: res_v) {
            cout << x + 1<< " ";
        }
        cout << "\n";
    }
    cout << res_e.size() << "\n";
    for (auto& x: res_e) {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    }

    return 0;
}