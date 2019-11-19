#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

#define ll long long
#define vll vector<long long>

#define fori(a, b) for(ll i = a;i <= b;i++)
#define forj(a, b) for(ll j = a;j <= b;j++)
#define fork(a, b) for(ll k = a;k <= b;k++)

#define input2(a, b) cin >> a >> b;
#define input(a) cin >> a;

#define max(a,b) (a<b?b:a)
#define min(a,b) (a>b?b:a)

using namespace std;

ll MOD = 9e18;

ll power(ll x, ll n, ll mod){
    if(n == 0){
        return 1;
    }
    ll temp = power(x, n/2, mod);
    if(n % 2 == 1){
        return (x*temp*temp)%mod;
    } else {
        return (temp*temp)%mod;
    }
}
ll abs(ll a, ll b){
    if(a > b){
        return a - b;
    }
    return b - a;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //
    ll t;
    cin >> t;
    ll a,b,c,d,k;
    ll f,s;
    fori(0, t-1){
        cin >> a >> b >> c >> d >> k;
        if(a % c == 0){
            f = a/c;
        } else {
            f = a/c + 1;
        }
        if(b % d == 0){
            s = b/d;
        } else {
            s = b/d + 1;
        }
        if(f + s <= k){
            cout << f << " " << s << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
