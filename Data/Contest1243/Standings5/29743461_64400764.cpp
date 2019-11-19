#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define f first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>

const int N = 1e5 + 1000, mod = 1e9 + 7;

ll bin_pow(int x, int y){
    if(y == 0)
        return 1;
    if(y == 1)
        return x;
    if(y % 2 == 0){
        ll z = bin_pow(x, y / 2);
        return (z * z) % mod;
    }
    return (bin_pow(x, y - 1) * x) % mod;
}


bool check(ll x){

}

int main(){
    boost;
    ll n;
    cin >> n;
    vector <ll> vec;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0)
            vec.pb(i);
        while(n % i == 0){
            n /= i;
        }
    }
    if(n != 1){
        vec.pb(n);
    }
    if(vec.size() == 1){
        cout << vec[0];
    }else{
        cout << 1;
    }
    return 0;
}
