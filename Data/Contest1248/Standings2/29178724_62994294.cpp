#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iomanip>

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

ll MOD = 1000000007;

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
ll n;
ll countt = 0;


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //
    ll a,b;
    cin >> a >> b;
    ll fib[max(a,b)+1];
    fib[1] = 1;
    fib[2] = 2;
    fori(3,max(a,b)){
        fib[i] = fib[i-1]+fib[i-2];
        fib[i] %= MOD;
    }
    cout << (2*(fib[a]+fib[b]-1))%MOD << endl;
    return 0;
}
