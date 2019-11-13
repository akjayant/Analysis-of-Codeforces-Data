//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define nl "\n"
#define fout(x) fixed<<setprecision(x)
#define one(x) __builtin_popcount(x)
#define F first
#define S second

const int MOD=1e9+7;
const double EPS=1e-9;
const double PI=acos(-1.0);

ll qpow(ll n,ll k){ll ans=1;assert(k>=0);n%=MOD;while(k>0){if(k&1)ans=(ans*n)%MOD;n=(n*n)%MOD;k>>=1;}return ans%MOD;}

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << fout(10)<<x;}
void __print(double x) {cerr << fout(10)<<x;}
void __print(long double x) {cerr << fout(10)<<x;}
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

// ****************************************************



int main()
{
    int tc;
    scanf("%d", &tc);
    for(int cs=1; cs<=tc; cs++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        int times=0;
        int mn=min(b, c/2);
        times=mn;
        b-=mn;
        mn=min(a, b/2);
        times+=mn;
        times*=3;
        cout<<times<<endl;
    }
    return 0;
}
