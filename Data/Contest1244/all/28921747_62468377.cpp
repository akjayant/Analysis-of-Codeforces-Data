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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, a, b, c, d, k;
    cin >> t;

    fori(q, t){
        cin >> n >> s;

        ll y = n;

        fori(i, n){
            if(s[i] == '1'){
                y = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == '1'){
                y = min(y, n - 1 - i);
                break;
            }
        }

        cout << max(n, (n - y) * 2) << "\n";
    }
}