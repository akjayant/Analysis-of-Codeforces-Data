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

    cin >> n >> m;

    map<ll, ll> mp;
    ll a;
    fori(i, n){
        cin >> a;
        ++mp[a];
    }

    while(m > 0 && mp.size() > 1){
        pll last = *(--mp.end());
        pll first = *mp.begin();

        if(last.ss < first.ss){
            mp.erase(last.ff);

            pll newLast = *(--mp.end());
            if((last.ff - newLast.ff) * last.ss <= m){
                m -= (last.ff - newLast.ff) * last.ss;
                (--mp.end())->ss += last.ss;
            }else {
                last.ff -= m / last.ss;
                m = 0;
                mp.insert(last);
            }
        }else{
            mp.erase(first.ff);

            pll newFirst = *mp.begin();
            if((newFirst.ff - first.ff) * first.ss <= m){
                m -= (newFirst.ff - first.ff) * first.ss;
                mp.begin()->ss += first.ss;
            }else {
                first.ff += m / first.ss;
                m = 0;
                mp.insert(first);
            }
        }
    }

    cout << (--mp.end())->ff - mp.begin()->ff;
}