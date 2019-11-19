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

ll MOD = 1;

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
ll XOR(ll a, ll b){
    ll result = 0;
    ll add = 1;
    while(a != 0 || b != 0){
        //cout << a << " " << b << endl;
        if(a % 2 != b % 2){
            result += add;
        }
        a /= 2;
        b /= 2;
        add *= 2;
    }
    return result;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //
    ll t;
    cin >> t;
    ll n;
    string str;
    ll frontt,backk;
    fori(0, t-1){
        cin >> n;
        cin >> str;
        frontt = 0;
        backk = 0;
        for(ll j = 0;j < n;j++){
            if(str[j] == '0'){
                frontt++;
            } else {
                break;
            }
        }
        for(ll j = n-1;j >= 0;j--){
            if(str[j] == '0'){
                backk++;
            } else {
                break;
            }
        }
        if(frontt == n){
            cout << n << endl;
            continue;
        }
        cout << 2*(n - min(frontt, backk)) << endl;
    }
    return 0;
}
