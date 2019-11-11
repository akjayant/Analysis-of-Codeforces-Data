#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define test() int t;cin>>t;loop(test,1,t+1)
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define nl cout<<"\n"
#define sp cout<<" "
#define F first
#define S second
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define MOD 1000000007
#define all(x) x.begin(),x.end()

template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }

ll mod( ll n, ll m=MOD ){ n%=m,n+=m,n%=m;return n; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<long long, int, custom_hash> safe_map;

const int MAXN = 1e5+5;
const int LOGN = 21;
const ll INF = 1e14;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

ll dp[MAXN];

void add( ll &x, ll y )
{
    x += y;
    if( x >= MOD )
        x -= MOD;
}

int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastio();

    string s;
    cin>>s;
    int n = s.size();
    int f = 0;

    dp[0] = 1;
    if( s[0] == 'm' || s[0] == 'w' )
        f = 1;
    if( n > 1 )
    {
        dp[1] = 1;
        if( s[0] == 'u' && s[1] == 'u' )
            dp[1] = 2;
        if( s[0] == 'n' && s[1] == 'n' )
            dp[1] = 2;
        if( s[1] == 'w' || s[1] == 'm' )
            f = 1;
    }
    for(int i=2;i<n;i++)
    {
        add(dp[i],dp[i-1]);
        if( s[i] == 'm' || s[i] == 'w' )
            f = 1;
        if( s[i] == 'u' && s[i-1] == 'u' )
            add(dp[i],dp[i-2]);
        else if( s[i] == 'n' && s[i-1] == 'n' )
            add(dp[i],dp[i-2]);
        // cout<<dp[i]<<" ";
    }
    if( f )
        dp[n-1] = 0;
    cout<<dp[n-1],nl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}