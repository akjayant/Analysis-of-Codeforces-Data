#include <iostream>
#include <vector>
using namespace std;
long long const mod = 1000000007;
long long mod_fact(int x){
    static vector<long long> fact = {1, 1};
    if(x < 0)return 0; //
    if(x < fact.size())return fact[x];
    for(int i = fact.size(); i <= x; i++){
        fact.push_back((fact[i-1] * i) % mod);
    }
    return fact[x];
}

long long mod_pow(long long a, long long b){
    long long res = 1;
    a %= mod;
    while(b > 0){
        if(b%2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

long long mod_div(long long a){
    return mod_pow(a, mod-2);
}

long long mod_comb(int a, int b){
    if(b < 0 || a < b)return 0;
    if(b > a/2)return mod_comb(a, a-b);
    return (((mod_fact(a) * mod_div(mod_fact(a-b))) % mod) * mod_div(mod_fact(b))) % mod;
}


int main(void){
    long long n, m, ans = 2;
    cin >> n >> m;
    for(int i = (n+1)/2; i < n; i++){
        ans += mod_comb(i, n-i) * 2;
        ans %= mod;
    }
    for(int i = (m+1)/2; i < m; i++){
        ans += mod_comb(i, m-i) * 2;
        ans %= mod;
    }
    cout << ans << endl;
}
