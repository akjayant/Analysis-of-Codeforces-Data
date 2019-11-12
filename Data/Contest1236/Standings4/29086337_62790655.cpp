#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

const int INF = 0x3c3c3c3c;
const ll INF_L = 0x3c3c3c3c3c3c3c3c;
const int MOD = 1e9 + 7;

ll myPow(ll v, ll c){
    ll res = 1;
    ll w = v;
    
    while(c){
        if(c & 1){
            res *= w;
            res %= MOD;
        }
        w *= w;
        w %= MOD;
        c /= 2;
    }
    return res;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    printf("%lld\n", myPow(myPow(2, m) - 1, n));
}