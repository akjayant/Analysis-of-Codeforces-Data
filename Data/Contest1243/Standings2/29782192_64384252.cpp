/// Radoslaw Mysliwiec 2019
#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

ll x;
vll divisor;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> x;

    for (ll i=2; i*i<=x; ++i){
        if (x%i == 0) {
            divisor.PB(i);
            divisor.PB(x/i);
        }
    }

    if (divisor.size() == 0){
        cout << x << endl;
        return 0;
    }

    ll gcd = x;

    for(auto u: divisor){
        gcd = __gcd(u,gcd);
    }

    cout << gcd << endl;

}
