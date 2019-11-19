#include <bits/stdc++.h>
 
#define loop(i, n) for(ll i = 0; i < n; i++)
#define loop1(i, a, n) for(int i = a; i < n; i++)
#define PI 3.141592653589793238
#define bc __builtin_popcountll
#define pf push_front
#define pb push_back
#define rf pop_front
#define rb pop_back
#define fs first
#define sc second
#define mp make_pair
#define fi ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
const ll M = 1e9 + 7;
const ll INF = 1e9;
inline ll pwr(ll base, ll n, ll m) {ll ans = 1;while( n > 0 ) {if ( n & 1 ) ans = (ans * base) % m; base = (base * base) % m; n>>=1;}return ans;}

const int N = 1e5 + 10;
ll dp[N];
int n, m;

int main() {
    fi;

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    #endif

    cin >> n >> m;
    ll w1[2] = {1, 2}, w2[2] = {1, 2};

    loop1(i, 2, n) {
        w1[i&1] = (w1[i&1] + w1[((i+1)&1)]) % M;
    }
    loop1(i, 2, m) {
        w2[i&1] = (w2[i&1] + w2[((i+1)&1)] ) % M;
    }

    ll ans = (w1[(n-1)&1] + w2[(m-1)&1] + M - 1) % M;
    ans = (ans*2) % M;
    cout << ans;

    return 0;
}