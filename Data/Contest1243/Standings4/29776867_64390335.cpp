#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define db double
#define ld long double
#define uint unsigned int
#define mp make_pair
#define pb push_back
#define sync std::ios::sync_with_stdio(false)
#define rep(i,l,r) for (int i = l, lim = r;i <= lim; ++i)
#define repr(i,l,r) for (int i = r, lim = l;i >= lim; --i)

int sc(int &x){return scanf("%d", &x);}
int sc(uint &x){return scanf("%u", &x);}
int sc(ll &x){return scanf("%lld", &x);}
int sc(ull &x){return scanf("%llu", &x);}
int sc(db &x){return scanf("%lf", &x);}
int sc(ld &x){return scanf("%Lf", &x);}
int sc(char *x){return scanf("%s", x);}
int sc(char &x){return scanf("%c", &x);}
template<typename T, typename... Args> void sc(T& v, Args&... args) { sc(v); sc(args...); }

void pr(const int &x){printf("%d", x);}
void pr(const uint &x){printf("%u", x);}
void pr(const ll &x){printf("%lld", x);}
void pr(const ull &x){printf("%llu", x);}
void pr(const db &x){printf("%.10lf", x);}
void pr(const ld &x){printf("%.10Lf", x);}
void pr(const char* const &x){printf("%s", x);}
void pr(char* const &x){printf("%s", x);}
void pr(const char &x){printf("%c", x);}
template<typename T, typename... Args> void pr(T const& v, Args const& ... args) { pr(v); pr(' '); pr(args...); }

#define sp pr(" ")
#define ln pr("\n")

const ll MOD = 1e9 + 7;
inline void _add(ll &a, ll b){a = (a + b) % MOD;}
inline void _sub(ll &a, ll b){a = (a + MOD - b) % MOD;}
inline void _mul(ll &a, ll b){a = (ll)a * b % MOD;}
inline ll _Add(ll a, ll b){return (a + b) % MOD;}
inline ll _Sub(ll a, ll b){return (a + MOD - b) % MOD;}
inline ll _Mul(ll a, ll b){return a * b % MOD;}

int main() {
    //sync;
    ll n;
    sc(n);
    int cnt = 0;
    ll num = n;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            cnt++;
            num = i;
        }
    }
    if (n > 1) cnt++;
    if (cnt > 1) pr(1);
    else pr(num);
    ln;
    return 0;
}

