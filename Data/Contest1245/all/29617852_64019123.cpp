# include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 3;

int n, c[N], k[N];
int x[N], y[N];
int p[N];
long long cur;
vector < pair <long long, pair <int, int> > > vec;

int f_s(int v) {
    return (p[v] == v) ? v: p[v] = f_s(p[v]);
}

void u_s(int a, int b) {
    a = f_s(a);
    b = f_s(b);
    if (a != b) {
        if (c[a] > c[b])
            swap(a, b);
        p[b] = a;
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        p[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cur += c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n ; j++) {
            long long dist = (abs(x[i] - x[j]) + abs(y[i] - y[j])) *1ll* (k[i] + k[j]);
            vec.push_back({dist, {i, j}});
        }
    }

    sort (vec.begin(), vec.end());

    int pos = -1;

    for (int i = 0; i < vec.size(); i++) {
        int a = vec[i].second.first, b = vec[i].second.second;
        if (f_s(a) != f_s(b)) {
            long long ret = cur + vec[i].first;
            ret -= max(c[f_s(a)], c[f_s(b)]);
            if (ret < cur) {
                cur = ret;
                pos = i;
                u_s(a, b);
            }
        }
    }

    for (int i = 1; i <= n; i++)
         p[i] = i;
    cout << cur << endl;
    vector < pair <int, int> > vv;
    vector <int> v;
    for (int i = 0; i <= pos; i++) {
        int a = vec[i].second.first, b = vec[i].second.second;
        if (f_s(a) != f_s(b)) {
            long long ret = cur + vec[i].first;
            ret -= max(c[f_s(a)], c[f_s(b)]);
            if (ret < cur) {
                cur = ret;
                u_s(a, b);
                vv.push_back({a, b});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            v.push_back(i);
        }
    }
    cout << v.size() << endl;
    for (int i : v)
        cout << i << " ";
    cout << endl;
    cout << vv.size() << endl;
    for (auto i : vv){
        cout << i.first << " " << i.second << endl;
    }
}
