#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define int long long

int n;
struct edge{
    int a, b, w;
};
vector<edge> e;

bool cmp(const edge& lhs, const edge& rhs){
    if(lhs.w != rhs.w) return lhs.w < rhs.w;
}

int p[2010];
int sz[2010];

vector<int> g[2010];

void make_set(int v){
    p[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(p[v] == v) return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        sz[b] = 0;
    }
}

int c[2010];
int k[2010];
int x[2010], y[2010];

int32_t main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    for(int i = 1; i <= n; i++){
        e.push_back({0, i, c[i]});
        for(int j = i + 1; j <= n; j++){
            int len = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            len *= (k[i] + k[j]);
            e.push_back({i, j, len});
        }
    }
    for(int i = 0; i <= n; i++){
        make_set(i);
    }
    sort(e.begin(), e.end(), cmp);
    int sum = 0;
    for(auto u : e){
        int from = u.a, to = u.b;
        if(find_set(from) != find_set(to)){
            union_sets(from, to);
            sum += u.w;
            g[from].push_back(to);
            g[to].push_back(from);
        }
    }
    cout << sum << '\n';
    cout << g[0].size() << '\n';
    for(auto u : g[0]) cout << u << ' '; cout << '\n';
    vector< pair<int,int> > an;
    for(int i = 1; i <= n; i++){
        for(int to : g[i]){
            if(i < to){
                an.push_back({i, to});
            }
        }
    }
    cout << an.size() << '\n';
    for(auto u : an){
        cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}
