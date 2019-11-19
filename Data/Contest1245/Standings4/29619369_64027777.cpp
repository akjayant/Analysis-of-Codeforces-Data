#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvvi> vvvvi;
typedef tuple<ll, ll, ll> iii;
typedef vector<iii> viii;

class UnionFind {
public:
    vi parent, rank;
    UnionFind(int n) {
        parent = rank = vi(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int findSet(int n) { return n == parent[n] ? n : parent[n] = findSet(parent[n]); }
    bool sameSet(int a, int b) { return findSet(a) == findSet(b); }
    void unionSet(int a, int b) {
        if (!sameSet(a, b)) {
            int x = findSet(a), y = findSet(b);
            if (rank[x] > rank[y]) parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi X(n), Y(n), C(n), K(n);
    for (int i = 0; i < n; ++i) cin >> X[i] >> Y[i];
    for (int i = 0; i < n; ++i) cin >> C[i];
    for (int i = 0; i < n; ++i) cin >> K[i];
    vi power;
    vii cable;
    UnionFind uf(n+1);
    viii P;
    for (int i = 0; i < n; ++i) P.push_back(iii(C[i], n, i));
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ll k = K[i] + K[j];
            ll total = (abs(X[i]-X[j]) + abs(Y[i]-Y[j])) * k;
            P.push_back(iii(total, i, j));
        }
    }
    sort(P.begin(), P.end());
    ll ans = 0;
    for (int i = 0; i < P.size(); ++i) {
        int a = get<1>(P[i]), b = get<2>(P[i]);
        if (!uf.sameSet(a, b)) {
            if (a == n) power.push_back(b+1);
            else cable.push_back({a+1, b+1});
            ans += get<0>(P[i]);
            uf.unionSet(a, b);
        }
    }
    cout << ans << "\n";
    cout << power.size() << "\n";
    for (int i = 0; i < power.size(); ++i) cout << power[i] << " ";
    cout << "\n";
    cout << cable.size() << "\n";
    for (int i = 0; i < cable.size(); ++i) cout << cable[i].F << " " << cable[i].S << "\n";
    return 0;
}