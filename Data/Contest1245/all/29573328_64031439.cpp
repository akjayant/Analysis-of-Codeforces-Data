#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int n;
long long x[4000];
long long y[4000];
long long c[4000];
long long k[4000];
vector<int> electro;
vector<pair<int, int>> cities;
long long sum = 0;
vector<tuple<long long, int, int>> m;

int sz[1000000];
int mn[1000000];
int mx[1000000];
int p[1000000];

int get(int a) {
    if (p[a] != a)
        p[a] = get(p[a]);
    return p[a];
}

void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (sz[b] < sz[a])
            swap(a, b);
        mn[b] = min(mn[b], mn[a]);
        mx[b] = max(mx[b], mx[a]);
        p[a] = b;
        sz[b] += sz[a];
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0 ; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0 ; i < n; ++i) {
        cin >> k[i];
    }
    for (int i = 0; i < n + 1; i++) {
        mn[i] = i;
        mx[i] = i;
        sz[i] = 1;
        p[i] = i;
    }
    size_t m_size = ((n + 1)* n) / 2;
    m.resize(m_size);
    int amount = 0;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = i + 1; j < n + 1; ++j) {
            if (j == n) {
                m[amount] = {c[i], i, j};
                m[amount] = {c[i], j, i};
            } else {
                long long edge = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
                m[amount] = {edge, i, j};
                m[amount] = {edge, j, i};
            }
            ++amount;
        }
    }
    sort(m.begin(), m.end());
    for (int i = 0; i < amount; ++i) {
        if (get(get<1>(m[i])) != get(get<2>(m[i]))) {
            if (get<1>(m[i]) == n || get<2>(m[i]) == n) {
                electro.push_back(min(get<1>(m[i]), get<2>(m[i])));
            } else {
                cities.emplace_back(get<1>(m[i]), get<2>(m[i]));
            }
            sum += get<0>(m[i]);
            join(get<1>(m[i]), get<2>(m[i]));
        }
    }
    cout << sum << endl;
    cout << electro.size() << endl;
    for (int i = 0; i < electro.size(); ++i) {
        cout << electro[i] + 1 << " ";
    }
    cout << endl;
    cout << cities.size() << endl;
    for (int i = 0; i < cities.size(); ++i) {
        cout << cities[i].first + 1 << " " << cities[i].second + 1 << endl;
    }
    return 0;
}