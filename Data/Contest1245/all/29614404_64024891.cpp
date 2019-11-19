#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FOD(i, a, b) for(int i = a; i >= b; i--)

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> iii;

const int N = 2010;
const int INF = 1e9;

ll n, x[N], y[N], c[N], k[N];
int root[N], cnt;
ll ans = 0;

vector <ii> edge;
vector <int> station;

ll Cost(int u, int v){
    ll len = abs(x[u] - x[v]) + abs(y[u] - y[v]);
    return len * (k[u] + k[v]);
}

int getRoot(int u){
    while (u != root[u]) u = root[u];
    return u;
}

bool mergeRoot(int u, int v){
    u = getRoot(u);
    v = getRoot(v);
    if (u == v) return 0;
    if (u > v)
        swap(u, v);
    root[v] = u;
    return 1;
}

int main(){
    cin >> n;
    FOR(i, 1, n)
        cin >> x[i] >> y[i];
    FOR(i, 1, n)
        cin >> c[i];
    FOR(i, 1, n)
        cin >> k[i];

    priority_queue <iii, vector<iii>, greater<iii> > Q;
    FOR(i, 1, n){
        root[i] = i;
        Q.push(mp(c[i], mp(0, i)));
    }
    FOR(u, 1, n)
        FOR(v, u + 1, n)
            Q.push(mp(Cost(u, v), mp(u, v)));
    while (!Q.empty()){
        ll w = Q.top().X;
        int u = Q.top().Y.X;
        int v = Q.top().Y.Y;
        Q.pop();
        if (mergeRoot(u, v)){
            ans += w;
            cnt++;
            if (u == 0)
                station.push_back(v);
            else
                edge.push_back(mp(u, v));
            if (cnt == n)
                break;
        }
    }
    cout << ans << endl;
    cout << station.size() << endl;
    for(int u : station) cout << u << ' ';
    cout << endl;
    cout << edge.size() << endl;
    for(ii e : edge)
        cout << e.X << ' ' << e.Y << endl;
}

