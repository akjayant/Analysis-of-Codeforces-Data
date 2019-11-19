/*
               _____
              /     \
              vvvvvvv  /|__/|
                 I   /O,O   |
                 I /_____   |      /|/|
                J|/^ ^ ^ \  |    /00  |    _//|
                 |^ ^ ^ ^ |W|   |/^^\ |   /oo |
                  \m___m__|_|    \m_m_|   \mm_|


 */
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

#define fori(a, r) for(long long int a = 0; a < (r); ++a)
#define forI(a, r) for(long long int a = 1; a <= (r); ++a)

#define ff first
#define ss second
#define pll pair<ll, ll>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long int ll;
typedef long double ld;

#define x first
#define y second
#define pt pair<ll, ll>

pt dxy[] = {{1,  0},
            {0,  1},
            {-1, 0},
            {0,  -1}};
ll months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long MAXN = 55, MOD = 1000000007, INF = ((1ll << 60) - 1) * 2 + 1;

mt19937 Umer(1337228);

ll n, m;
string s;

ll c[3][100 * 1000];
ll curC[100 * 1000];
ll bestC[100 * 1000];
bool u[100 * 1000];
vector<ll> g[100 * 1000];
ll cost;

void r(ll clr, ll prev, ll v){
    u[v] = true;
    ll cur;
    fori(i, 3){
        if(i != clr && i != prev){
            cur = i;
            cost += c[i][v];
            break;
        }
    }

    curC[v] = cur + 1;

    for(ll to: g[v]){
        if(!u[to]){
            r(cur, clr, to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    fori(j, 3) {
        fori(i, n) {
            cin >> c[j][i];
        }
    }
    ll a, b;
    fori(i, n - 1){
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ll v;
    fori(i, n){
        if(g[i].size() == 1){
            v = i;
        }else if(g[i].size() >= 3){
            cout << -1;
            return 0;
        }
    }

    ll minn = INF;

    fori(i, 3){
        fori(j, 3){
            if(i == j) continue;

            cost = 0;
            r(i, j, v);
            fori(i, n) u[i] = false;

            if(minn > cost){
                minn = cost;
                fori(i, n) bestC[i] = curC[i];
            }
        }
    }

    cout << minn << "\n";
    fori(i, n) cout << bestC[i] << " ";
}