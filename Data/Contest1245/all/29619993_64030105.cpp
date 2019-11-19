#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<int> parent, ran;

void make_set(int v) {
    parent[v] = v;
    ran[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ran[a] < ran[b])
            swap(a, b);
        parent[b] = a;
        if (ran[a] == ran[b])
            ran[a]++;
    }
}

struct Edge {
    int u, v;
    ll weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};



int main()
{
int n;
vector<Edge> edges;

cin>>n;
vector<int> X(n+1);
vector<int> Y(n+1);
vector<int> C(n+1);
vector<int> K(n+1);
for(int i = 1; i<=n; i++){
    cin>>X[i]>>Y[i];
}
for(int i = 1; i<=n; i++){
    cin>>C[i];
}
for(int i = 1; i<=n; i++){
    cin>>K[i];
}
for(int i = 1; i<=n; i++){
    Edge e1, e2;
    e1.u = 0;
    e1.v = i;
    e1.weight = C[i];
    e2.u = i;
    e2.v = 0;
    e2.weight = C[i];
    edges.push_back(e1);
    edges.push_back(e2);
}

for(int i = 1; i<=n; i++){
    for(int j = i+1; j<=n; j++){
        if(i == j) continue;
        ll dist = (K[i] + K[j]) * 1ll * (abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
        Edge e1, e2;
        e1.u = i;
        e1.v = j;
        e1.weight = dist;
        e2.u = j;
        e2.v = i;
        e2.weight = dist;
        edges.push_back(e1);
        edges.push_back(e2);
    }
}

n = n+1;
ll cost = 0;
vector<Edge> result;
parent.resize(n);
ran.resize(n);
for (int i = 0; i < n; i++)
    make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}
vector<Edge> stat;
for(Edge e: result){
    if(e.u == 0 || e.v == 0) stat.push_back(e);
}
cout<<cost<<endl;
cout<<stat.size()<<endl;
for(Edge e: stat){
    cout<<(e.u == 0?e.v:e.u)<<" ";
}
cout<<endl;
cout<<result.size() - stat.size()<<endl;
for(Edge e: result){
    if(e.u == 0 || e.v == 0) continue;
    cout<<e.u<<" "<<e.v<<'\n';
}
    return 0;
}
