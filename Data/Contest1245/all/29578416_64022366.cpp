#include <bits/stdc++.h>
using namespace std;

void run();

signed main(){
    cout.setf(ios::fixed);
    cout.precision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

struct Point{
    int x, y;
    Point(int a = 0, int b = 0){
        x = a;
        y = a;
    }
};

int operator - (Point &a, Point &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct DSU{
    int parent, size, num; // cost of energy
};

const int MAXN = 2000 + 10;
Point point[MAXN];
int cost[MAXN], k[MAXN];
DSU dsu[MAXN];
bool energy[MAXN];


int parent_dsu(int v){
    if (dsu[v].parent == v)
        return v;
    return dsu[v].parent = parent_dsu(dsu[v].parent);
}

int ask_min_dsu(int v){
    v = parent_dsu(v);
    return cost[dsu[v].num];
}

bool ask_dsu(int v, int u){
    v = parent_dsu(v);
    u = parent_dsu(u);
    return v == u;
}

void join_dsu(int v, int u){
    if (ask_dsu(v, u))
        return;
    v = parent_dsu(v);
    u = parent_dsu(u);
    if (dsu[v].size < dsu[u].size)
        swap(v, u);
    if (cost[dsu[v].num] < cost[dsu[u].num]){
        dsu[v].num = dsu[v].num;
    } else{
        dsu[v].num = dsu[u].num;
    }
    dsu[v].size += dsu[u].size;
    dsu[u].parent = v;
}

void run(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> point[i].x >> point[i].y;
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++)
        cin >> k[i];
    for (int i = 0; i < n; i++){
        dsu[i].size = 1;
        dsu[i].num = i;
        dsu[i].parent = i;
    }
    set <pair<long long, pair<int, int>>> order;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            order.emplace(1LL * (k[i] + k[j]) * (point[i] - point[j]), make_pair(i, j));
        }
    }
    vector <pair<int, int>> ans2;
    long long sum = 0;
    while (!order.empty()){
        auto temp = (*order.begin());
        order.erase(order.begin());
        int v = temp.second.first, u = temp.second.second;
        if (ask_dsu(v, u))
            continue;
        if (max(ask_min_dsu(u), ask_min_dsu(v)) >= temp.first){
            join_dsu(v, u);
            ans2.emplace_back(v, u);
            sum += temp.first;
        }
    }
    vector <int> ans1;
    for (int i = 0; i < n; i++){
        int v = parent_dsu(i);
        energy[dsu[v].num] = true;
    }
    for (int i = 0; i < n; i++){
        if (energy[i]){
            ans1.push_back(i);
            sum += cost[i];
        }
    }
    cout << sum << '\n';
    cout << ans1.size() << '\n';
    for (auto &i: ans1)
        cout << i + 1 << " ";
    cout << '\n';
    cout << ans2.size() << '\n';
    for (auto &i: ans2)
        cout << i.first + 1 << " " << i.second + 1 << '\n';
}




