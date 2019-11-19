#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int>x(n), y(n);
    auto dist = [&] (int i, int j) ->long long {
        return abs(x[i] - x[j]) + abs(y[i] - y[j]);
    };
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int>c(n), k(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        cin >> k[i];

    vector<tuple<long long, int, int>>E;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            E.push_back(make_tuple((1LL * k[i] + k[j]) * dist(i, j), i, j));

        }
        E.push_back(make_tuple(c[i], i, i + n));
        E.push_back(make_tuple(0, 2 * n, i + n));

    }
    sort(E.begin(), E.end());
    vector<int>dad(n + n + 1);
    for(int i = 0; i < 2 * n + 1; ++i) {
        dad[i] = i;
    }
    function<int(int)>DD = [&] (int u) {
        if(u == dad[u]) return u;
        return dad[u] = DD(dad[u]);
    };
    auto join = [&] (int u, int v) {
        dad[DD(u)] = DD(v);
    };

    long long cst = 0;
    vector<int>connections;
    vector<pair<int, int>>built;
    for(auto it : E) {
        if(DD(get<1>(it)) != DD(get<2>(it))) {
            join(get<1>(it), get<2>(it));
            cst += get<0>(it);
            if(get<2>(it) >= n) {
                if(get<1>(it) < n)

                    connections.push_back(get<2>(it) - n);
            }
            else if(get<1>(it) < n && get<2>(it) < n)
                built.push_back(make_pair(get<1>(it), get<2>(it)));

        }
    }
    cout << cst << '\n';
    cout << connections.size() << '\n';
    for(int x: connections)
        cout << x+1<<' ';
    cout << '\n';
    cout << built.size() << '\n';
    for(pair<int, int>p : built)
        cout << p.first+1<<' '<<p.second+1<<'\n';
    return 0;


}

