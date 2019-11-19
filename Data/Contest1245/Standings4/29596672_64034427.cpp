#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define num     int
#define llg     long long

llg absolute(llg x) {
    return std::max(x, -x);
}

#define MAXN    2005

int N;
std::vector <std::pair <int, int>> V;
std::vector <std::pair <int, int>> ans;
std::vector <int> edges2[MAXN];
std::vector <llg> C, K;

inline void addEdge(int x, int y) {
    edges2[x].push_back(y);
    edges2[y].push_back(x);
    ans.push_back({x, y});
}

llg cost[MAXN];
llg min[MAXN];
int parent[MAXN], rang[MAXN];

int _find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = _find(parent[x]);
}
void _union(int x, int y, llg w, int orig_x, int orig_y) {
    //std::cout << "hi\n";
    if (x == y) return;
    //std::cout << "bye\n";
    addEdge(orig_x, orig_y);
    if (rang[x] == rang[y]) {
        ++ rang[x];
        parent[y] = x;
        cost[x] = cost[x] + cost[y] + w - std::max(min[x], min[y]);
        min[x] = std::min(min[x], min[y]);
        cost[y] = min[y] = 0;
    }   else
    if (rang[x] < rang[y]) {
        parent[x] = y;
        cost[y] = cost[x] + cost[y] + w - std::max(min[x], min[y]);
        min[y] = std::min(min[x], min[y]);
        cost[x] = min[x] = 0;
    }
    else {
        parent[y] = x;
        cost[x] = cost[x] + cost[y] + w - std::max(min[x], min[y]);
        min[x] = std::min(min[x], min[y]);
        cost[y] = min[y] = 0;
    }
}

struct edge {
    int x, y;
    llg w;
    bool operator < (const edge& other) const {
        return w < other.w;
    }
};  std::vector <edge> edges;

bool seen[MAXN];
int vv;
void DFS(int vertex) {
    if (vv == -1) vv = vertex;
    else if (C[vertex] < C[vv]) vv = vertex;
    seen[vertex] = true;
    for (auto &it:edges2[vertex])
        if (!seen[it])
            DFS(it);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    input >> N;
    V.resize(N);
    C.resize(N);
    K.resize(N);

    for (auto &it:V) input >> it.first >> it.second;
    int cnt = 0;
    for (auto &it:C) input >> it, min[cnt] = cost[cnt] = it, cnt++;
    for (auto &it:K) input >> it;

    for (int i=0, j; i<N; ++i)
        for (j=i+1; j<N; ++j) {
            llg val = (K[i]+K[j]) * (absolute(V[i].first-V[j].first) + absolute(V[i].second-V[j].second));
            //if (val >= C[i] && val >= C[j]);
            //else edges.push_back({i, j, val});
            edges.push_back({i, j, val});
        }

    std::sort(edges.begin(), edges.end());
    for (int i=0; i<N; ++i)
        parent[i] = i;

    int idx = 0;
    while (idx < edges.size()) {
        int x = edges[idx].x, y = edges[idx].y;
        llg w = edges[idx].w;
        //std::cout << "edge " << x << ' ' << y << ' ' << w << '\n';
        x = _find(x);
        y = _find(y);
        //std::cout << "edge " << x << ' ' << y << '\n';
        //std::cout << "edge " << cost[x] << ' ' << cost[y] << '\n';
        //std::cout << "edge " << min[x] << ' ' << min[y] << '\n';
        llg v = cost[x] + cost[y] + w - std::max(min[x], min[y]);
        //std::cout <<  v << '\n';
        if (v < cost[x] + cost[y]) _union(x, y, w, edges[idx].x, edges[idx].y);
        ++ idx;
    }

    std::vector <int> ans2;
    for (int i=0; i<N; ++i)
        if (!seen[i])
            vv = -1, DFS(i), ans2.push_back(vv);

    llg sum = 0;
    for (int i=0; i<N; ++i)
        sum += cost[i];
    output << sum << '\n';

    output << ans2.size() << '\n';
    for (auto &it:ans2) output << it+1 << ' ';
    output << '\n';
    output << ans.size() << '\n';
    for (auto &it:ans) output << it.first+1 << ' ' << it.second+1 << '\n';

    return 0;
}

/*
5
1 1
1 2
1 3
1 4
1 5
10 10 10 10 10
1 1 1 1 1
*/
