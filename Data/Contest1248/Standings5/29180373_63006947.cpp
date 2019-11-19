#include<bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define A first
#define B second
#define MOD 1000000007

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int mulmd(ll a, ll b){
    ll ret = (a * b) % MOD;
    return (int)ret;
}

inline int power(ll x, ll y, int p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = mulmd(res, x);
        y = y >> 1;
        x = mulmd(x, x);
    }
    return (int)res;
}

int submd(ll a, ll b){
    ll ret = a - b;
    if(ret < 0){
        ret += MOD;
    }
    return (int)ret;
}

int addmd(ll a, ll b){
    ll ret = (a + b) % MOD;
    return (int)ret;
}

int invPow(ll a){
    return power(a, MOD - 2, MOD);
}

const int N = 1e5 + 5;

int dp1[N][2];
int dp2[N][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    dp1[1][0] = 1;
    dp1[1][1] = 0;
    FOR(i, 2, n){
        dp1[i][0] = addmd(dp1[i - 1][0], dp1[i - 1][1]);
        dp1[i][1] = dp1[i - 1][0];
    }
    dp2[1][0] = 1;
    dp2[1][1] = 0;
    FOR(i, 2, m){
        dp2[i][0] = addmd(dp2[i - 1][0], dp2[i - 1][1]);
        dp2[i][1] = dp2[i - 1][0];
    }
    int ans = addmd(dp1[n][0], dp1[n][1]);
    ans = mulmd(ans, 2);
    ans = addmd(ans, mulmd(submd(addmd(dp2[m][0], dp2[m][1]), 1), 2));
    cout << ans;
}

/**
    Check out for boundary cases, (n = 1 or n = 0)
    check for integer overflow

**/

