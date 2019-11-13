#include <bits/stdc++.h>
using namespace std;
#if LOCAL
#include "debug.h"
#endif
#define endl '\n'
#define rep(i, begin, end) for (__typeof(end+0) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
typedef unsigned int uint; typedef unsigned long ul; typedef unsigned long long ull;
typedef long long ll; typedef long double ld; typedef unsigned char uchar;
struct secure_hash {
 static uint64_t splitmix64(uint64_t x) {
  x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); }
 size_t operator()(uint64_t x) const {
  static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
template<typename T> using V = vector<T>;
template<typename T, typename U> using umap = unordered_map<T,U,secure_hash>;
template<typename T> using uset = unordered_set<T,secure_hash>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

const ll M = 1e9 + 7;

ll mpow(ll a, ll n)
{
    if (n == 0) return 1;
    if (n % 2 == 0) return mpow(a*a % M, n/2);
    return a * mpow(a*a % M, (n-1)/2) % M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll b = (mpow(2, m) - 1 + M) % M;
    cout << mpow(b, n) << endl;
}
