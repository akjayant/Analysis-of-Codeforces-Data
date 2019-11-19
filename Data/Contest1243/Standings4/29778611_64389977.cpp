#define pb push_back
#define mod 1000000009
#define ff first
#define ss second
#define maxn 100005
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;


int main(int argc, char const *argv[]) {
    ll n;
    vector<ll> v;
    cin >> n;
    if(n == 1){
        cout << n << endl;
        return 0;
    }
    for(ll i=1;i*i<=n;i++){
        if(n%i == 0){
            v.pb(i);
            if(n/i != i) v.pb(n/i);
        }
    }
    sort(v.begin(), v.end());
    ll gcd = 0;
    for(int i=1;i<v.size();i++){
        gcd = __gcd(gcd, v[i]);
    }
    cout << gcd << endl;

    return 0;
}
