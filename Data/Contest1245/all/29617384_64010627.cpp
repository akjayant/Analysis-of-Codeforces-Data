#define DEBUG 1
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
#define all(v) (v).begin(), (v).end()
#define for1(i, n) for (ll i = 0; i < (n); i++)
#define for2(i, m, n) for (ll i = (m); i < (n); i++)
#define for3(i, m, n, d) for (ll i = (m); i < (n); i += (d))
#define rfor2(i, m, n) for (ll i = (m); i > (n); i--)
#define rfor3(i, m, n, d) for (ll i = (m); i > (n); i += (d))
#define PI 3.1415926535897932384626433832795028841971693993751
#define INF 1111111111111111111LL
#define MOD 1000000007LL  // 10**9 + 7
#define print(...) print_1(__VA_ARGS__)
#define in(...) in_1(__VA_ARGS__)
#if DEBUG
#define dump(...) dump_1(#__VA_ARGS__, __VA_ARGS__)
#define dumpa(...) dumpa_1(#__VA_ARGS__, __VA_ARGS__)
#else
#define dump(...)
#define dumpa(...)
#endif
template <typename Head>
void dump_1(const char* str, Head&& h)
{
    cerr << str << ": " << h << '\n';
}
template <typename Head, typename... Tail>
void dump_1(const char* str, Head&& h, Tail&&... t)
{
    while (*str != ',') {
        cerr << *str++;
    }
    cerr << ": " << h << ' ';
    dump_1(str + 1, t...);
}
template <typename T>
void dumpa_1(const char* str, const T v[], const ll size)
{
    while (*str != ',') {
        cerr << *str++;
    }
    cerr << ": ";
    for1 (i, size) {
        if (i != 0) {
            cerr << ' ';
        }
        cerr << v[i];
    }
    cerr << '\n';
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& v)
{
    os << '(' << v.first << ", " << v.second << ')';
    return os;
}
template <typename T1, typename T2, typename T3>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3>& v)
{
    os << '(' << get<0>(v) << ", " << get<1>(v) << ", " << get<2>(v) << ')';
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ' ';
        }
        os << *it;
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ' ';
        }
        os << *it;
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ' ';
        }
        os << *it;
    }
    return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& v)
{
    os << '{';
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ", ";
        }
        os << it->first << ':' << it->second;
    }
    os << '}';
    return os;
}
void Yes(void) { cout << "Yes\n"; }
void No(void) { cout << "No\n"; }
void YES(void) { cout << "YES\n"; }
void NO(void) { cout << "NO\n"; }
template <typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
void vin(vector<T>& v, ll len)
{
    for1 (i, len) {
        cin >> v[i];
    }
}
template <typename Head>
void in_1(Head& h)
{
    cin >> h;
}
template <typename Head, typename... Tail>
void in_1(Head& h, Tail&... t)
{
    cin >> h;
    in_1(t...);
}
template <typename Head>
void print_1(Head&& h)
{
    cout << h << '\n';
}
template <typename Head, typename... Tail>
void print_1(Head&& h, Tail&&... t)
{
    cout << h << ' ';
    print_1(t...);
}
//---------------------------------------------------------
void solve()
{
    ll T;
    in(T);
    for1 (t, T) {
        ll n, a, b, c;
        in(n, a, b, c);
        string s;
        in(s);
        ll len = s.size();
        ll a2 = 0;
        ll b2 = 0;
        ll c2 = 0;
        bool ok = false;
        for1 (i, len) {
            char ch = s[i];
            if (ch == 'R') {
                b2++;
            }
            else if (ch == 'P') {
                c2++;
            }
            else if (ch == 'S') {
                a2++;
            }
        }
        ll a3 = min(a, a2);
        ll b3 = min(b, b2);
        ll c3 = min(c, c2);
        // dump(a, b, c);
        // dump(a2, b2, c2);
        // dump(a3, b3, c3, (n + 1) / 2);
        if (a3 + b3 + c3 >= (n + 1) / 2) {
            YES();
            string ans(len, ' ');
            for1 (i, len) {
                char ch = s[i];
                if (ch == 'R') {
                    if (b > 0) {
                        ans[i] = 'P';
                        b--;
                    }
                }
                else if (ch == 'P') {
                    if (c > 0) {
                        ans[i] = 'S';
                        c--;
                    }
                }
                else if (ch == 'S') {
                    if (a > 0) {
                        ans[i] = 'R';
                        a--;
                    }
                }
            }
            for1 (i, len) {
                char ch = ans[i];
                // dump(i, ch, a, b, c);
                if (ch == ' ') {
                    if (b > 0) {
                        ans[i] = 'P';
                        b--;
                    }
                    else if (c > 0) {
                        ans[i] = 'S';
                        c--;
                    }
                    else if (a > 0) {
                        ans[i] = 'R';
                        a--;
                    }
                }
            }
            print(ans);
            ok = true;
        }
        if (!ok) {
            NO();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(16);
    cerr << fixed << setprecision(16);
    solve();
}
