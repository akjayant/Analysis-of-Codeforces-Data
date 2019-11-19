#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000007
using namespace std;

vector <int> g[200010];
bool used[200010];
vector <int> cmp;
set <int> a, tmp;
int n, m;

void process(int u) {
    for (auto v : g[u]) {
        if (a.count(v)) {
            a.erase(v);
            tmp.insert(v);
        }
    }
    vector <int> to;
    while(!a.empty()) {
        int x = *a.begin();
        a.erase(a.begin());
        ++cmp.back();
        used[x] = 1;
        to.push_back(x);
    }
    swap(a, tmp);
    for (auto v : to) {
        process(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i){
            a.insert(i);
    }
    for (int u = 1; u <= n; ++u) {
        if (used[u]){
            continue;
        }
        cmp.push_back(1);
        a.erase(u);
        process(u);
    }
    cout << (int)cmp.size() - 1;
    return 0;
}
