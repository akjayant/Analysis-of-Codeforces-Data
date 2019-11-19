#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

std::default_random_engine generator;
int rnd(int l, int r)
{
    std::uniform_int_distribution<int> distribution(l, r);
    return distribution(generator);
}

template<class T> inline T gcd(T a, T b)
{
    if(a < 0) return gcd(-a, b);
    if(b < 0) return gcd(a, -b);
    return (b==0) ? a : gcd(b, a%b);
}

template<class T> inline T lcm(T a, T b)
{
    return a / gcd(a, b) * b;
}

const long long mod = 1e9+7;
const double pi = 3.141592653589793238462643383279;

long long powmod(long long x, long long p)
{
    if(p == 0)
        return 1;
    if(p&1)
        return x * powmod(x*x%mod, p/2) % mod;
    else
        return powmod(x*x%mod, p/2) % mod;
}

class Dsu {
public:
    vector<int> p;
    int n;
    
    Dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(12);
    cout << fixed;
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> c(n), k(n), x(n), y(n);
    vector<vector<long long>> edges;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < i; ++j) {
            edges.push_back({(k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), i, j});
        }
        edges.push_back({c[i], i, n});
    }
    sort(edges.begin(), edges.end());
    long long min_cost = 0;
    vector<int> stations;
    vector<vector<int>> connections;
    Dsu dsu(n+1);
    for (auto& edge : edges) {
        long long cost = edge[0];
        int i = int(edge[1]);
        int j = int(edge[2]);
        if (dsu.unite(i, j)) {
            min_cost += cost;
            if (j == n) {
                stations.push_back(i+1);
            } else {
                connections.push_back({i+1, j+1});
            }
        }
    }
    cout << min_cost << '\n';
    cout << stations.size() << '\n';
    for (int x : stations)
        cout << x << ' ';
    cout << '\n' << connections.size() << '\n';
    for (auto& v : connections)
        cout << v[0] << ' ' << v[1] << '\n';

    
    return 0;
}
