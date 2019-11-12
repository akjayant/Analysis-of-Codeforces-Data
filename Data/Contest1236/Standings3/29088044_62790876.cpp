#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <math.h>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;

const ll mod = 1e9 + 7;

ll square (ll a){
    return (a * a) % mod;
}

ll power (ll n, ll k){
    if (k == 0) return 1;
    if (k == 1) return n % mod;
    if (k%2 == 0) return square(power(n, k/2));

    return (n * power(n, k-1)) % mod;
}

int main (){
    ll n, m;
    cin >> n >> m;

    ll present = power(2, m) - 1;
    ll total = power(present, n);

    cout << total << endl;
}   