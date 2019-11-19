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
ll a[N];
int n;

int main() {
    fi;

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    #endif

    cin >> n;
    
    loop(i, n)
        cin >> a[i];
    
    sort(a, a+n);

    ll x = 0, y = 0, i = 0, j = n-1, k = 0;
    
    if( (n & 1) ) {
        x += a[j];
        j--;
        n--;
    }

    while( n > 0 ) {
        y += a[i];
        i++;
        n--;
        if( n > 0 ) {
            x += a[j];
            j--;
            n--;
        }
    }

    ll ans = (x*x) + (y*y);
    cout << ans;

    return 0;
}