#include<bits/stdc++.h>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mod 1000000007
#define INF 1e18
#define ALPHABET_SIZE 26


using namespace std;
typedef long long ll;

/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( ) 
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/

long long pang(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a;

    ll ret = pang(a, b/2);
    ret = (ret * ret) % mod;

    if(b % 2 == 1){
        ret = (ret * a) % mod;
    }
    return ret;
}


int main(){
    long long n,m; cin >> n >> m;

    long long now = (pang(2, m) + mod - 1) % mod;

    now = pang(now, n);

    cout << now << "\n";


}
