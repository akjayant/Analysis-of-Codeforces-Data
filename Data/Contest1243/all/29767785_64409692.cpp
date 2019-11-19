#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m;
int u, v;
vector< set<int> > adjList;

vector< pair<int,int> > deg;
vector<int> ds;

vector<int> processed;

int parent(int u) {
    if (ds[u] == u) return u;
    return ds[u] = parent(ds[u]);
}

void mergeSet(int u, int v) {
    int uu = parent(u);
    int vv = parent(v);
    if (uu != vv) ds[uu] = vv;
}

int main() {
    cin >> n >> m;
    adjList.assign(n+1, set<int>());
    ds.assign(n+1, 0);
    processed.assign(n+1, 0);
    
    while (m--) {
        cin >> u >> v;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
    
//    cout << "output" << endl;
    
    for (int i = 1; i <= n; i++) {
        deg.push_back(make_pair((int)adjList[i].size(), i));
        ds[i] = i;
//        cout << i << ' ' << (int)adjList[i].size() << endl;
    }
    
    sort(deg.begin(), deg.end());
    
    for (int ix = 0; ix < n; ix++) {
        u = deg[ix].second;
//        cout << u << ' ' << deg[ix].first << endl;
        if (processed[u] >= 3) continue;
        for (int i = 1; i <= n; i++) {
            if (i == u) continue;
            if (adjList[u].find(i) == adjList[u].end()) {
                mergeSet(u, i);
                processed[u]++;
                processed[i]++;
            }
        }
    }
    
    set<int> ans;
    for (int i = 1; i <= n; i++) {
//        cout << i << ' ' << parent(i) << endl;
        ans.insert(parent(i));
    }
    
    cout << (int)ans.size() - 1 << endl;
}
