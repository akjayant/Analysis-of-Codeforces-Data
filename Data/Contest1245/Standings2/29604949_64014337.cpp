#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

struct node{
    int k, p;
};

node v[3000];

int find_set(int x){
    if (v[x].p == x)
        return x;
    return v[x].p = find_set(v[x].p);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        if (v[a].k > v[b].k){
            v[a].k += v[b].k;
            v[b].p = a;
        }
        else{
            v[b].k += v[a].k;
            v[a].p = b;
        }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <pair<int, int> > q(n);
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    vector <pair<int, pair<int, int> > > e;
    vector <int> c(n), k(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            e.push_back({(abs(q[i].first - q[j].first) + abs(q[i].second - q[j].second)) * (k[i] + k[j]), {i + 1, j + 1}});
    for (int i = 0; i < n; i++)
        e.push_back({c[i], {0, i + 1}});
    sort(e.begin(), e.end());
    unsigned int ans = 0;
    vector <int> ansv;
    vector <pair<int, int> > anse;
    for (int i = 0; i <3e3; i++){
        v[i].p = i;
        v[i].k = 1;
    }
    for (int i = 0; i < e.size(); i++){
        if (find_set(e[i].second.first) != find_set(e[i].second.second)){
            ans += e[i].first;
            union_sets(e[i].second.first, e[i].second.second);
            if (e[i].second.first == 0)
                ansv.push_back(e[i].second.second);
            else
            anse.push_back({e[i].second.first, e[i].second.second});
        }
    }
    cout << ans << '\n';
    cout << ansv.size() << '\n';
    for (int i = 0; i < ansv.size(); i++)
        cout << ansv[i] << ' ';
    cout << '\n';
    cout << anse.size() << '\n';
    for (int i = 0; i < anse.size(); i++)
        cout << anse[i].first << ' ' << anse[i].second << '\n';
    return 0;
}
