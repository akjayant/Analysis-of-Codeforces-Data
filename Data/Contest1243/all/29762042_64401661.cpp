#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstring>
#include <cassert>
 
#include <sstream>
#include <fstream>
#include <iostream>
#include <limits>
 
#include <stack>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;
 
#define mp make_pair
#define pb push_back
#define UNKNOWN -1
#define INF 1<<30LL
#define ff first
#define ss second
#define EPSILON 0.00000001
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repi(i, b, a) for(int i = (b) - 1; i >= (a); i--)
#define rp(i, a) rep(i, 0, a)
#define SET(x, a) memset((x), (a), sizeof(x))
#define ALL(vec) begin(vec), end(vec)
#define SORT(v) sort(ALL(v))
#define endl "\n"
#define SZ(v) int((v).size())
 
#define __DEBUG__
#ifdef __DEBUG__
    #define d(args...)  {cout << "> "; dbg,args; cout<<endl;}
#else
    #define d(args...)
#endif
#ifdef __DEBUG__
    #define dd(args...)  {dbg,args; cout << " ";}
#else
    #define dd(args...)
#endif
using namespace std;
 
//debugs everything
struct debugger{template<typename T> debugger& operator , (const T& v)
    {cout<<v<<" ";return *this;}}dbg;
 
 
typedef pair<int, int> ii;
typedef pair<int, ii> ip;
typedef pair<ii, int> pi;
typedef pair<ii, ii> pp;
typedef vector<ip> gip;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef pair<ll, ll> pll;

ll MAXN = 1001001;
ll SQRTMAXN = 1010;

int main()
{
    ll n;
    cin >> n;
    vb prime(MAXN, true);
    prime[0] = prime[1] = false;
    rep (i, 2, SQRTMAXN)
        for (ll j = 2 * i; j <= MAXN; j += i)
            prime[j] = false;
    bool is_prime = true;
    rp (i, MAXN)
        if (prime[i] and i < n and n % i == 0) {is_prime = false; break;}
    if (is_prime) {cout << n << "\n"; return 0;}
    int approx_log = ceil(log2(double(n)));
    rep (i, 2, approx_log + 1) {
        double i_root = pow(double(n), 1./i);
        ll t1 = ceil(i_root);
        ll t2 = floor(i_root);
        if (pow(t1, i) == n and prime[t1]) {cout << t1 << "\n"; return 0;}
        if (pow(t2, i) == n and prime[t2]) {cout << t2 << "\n"; return 0;}
    }
    cout << "1\n";
    return 0;
}

