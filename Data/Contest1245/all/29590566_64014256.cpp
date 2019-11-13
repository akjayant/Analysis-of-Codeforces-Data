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

ll binary(ll n){
    ll sum = 0;
    if(n <= 0){
        return 10000000;
    }
    while(n > 0){
        if(n % 2 == 1){
            sum++;
        }
        n /= 2;
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //
    string str;
    cin >> str;
    char last = '1';
    ll count = 1;
    ll sol = 1;
    ll f[100002];
    f[1] = 1;
    f[2] = 2;
    fori(3, 100000){
        f[i] = f[i-1] + f[i-2];
        f[i] %= MOD;
    }
    fori(0, str.length()-1){
        if(str[i] == 'm' || str[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
        if(str[i] == last){
            count++;
        } else {
            if(last == 'u' || last == 'n'){
                sol *= f[count];
                sol %= MOD;
                
            }
            count = 1;
            last = str[i];
        }
    }
    if(last == 'u' || last == 'n'){
        sol *= f[count];
        sol %= MOD;
        count = 1;
    }
    cout << sol << endl;
    return 0;
}
