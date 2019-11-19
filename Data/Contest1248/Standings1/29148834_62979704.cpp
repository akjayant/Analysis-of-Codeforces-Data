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
int a[N], b[N], n, m;

int main() {
    fi;

    #ifndef ONLINE_JUDGE
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    #endif

    int t;
    cin >> t;

    while(t--) {

        cin >> n;
        ll e1 = 0, o1 = 0, e2 = 0, o2 = 0;
        loop(i, n) {
            cin >> a[i];
            if( (a[i] & 1)) o1 ++;
            else e1++;
        }
        
        cin >> m;
        loop(i, m) {
            cin >> b[i];
            if( (b[i] & 1)) o2 ++;
            else e2++;
        }

        ll ans = (o1*o2) + (e1*e2);
        cout << ans << "\n";
    }

    return 0;
}