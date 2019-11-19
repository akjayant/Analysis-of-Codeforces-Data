// Created by sz
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1000 * 1000 * 1000 +7;
struct modular {
    int value;
    modular(long long v = 0) { value = v % mod; if (value < 0) value += mod;}
    modular(long long a, long long b) : value(0){ *this += a; *this /= b;}
    modular& operator+=(modular const& b) {value += b.value; if (value >= mod) value -= mod; return *this;}
    modular& operator-=(modular const& b) {value -= b.value; if (value < 0) value += mod;return *this;}
    modular& operator*=(modular const& b) {value = (long long)value * b.value % mod;return *this;}
    //其他函数调用mexp(modular(10),3);
    friend modular mexp(modular a, long long e) {
        modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
        return res;
    }
    friend modular inverse(modular a) { return mexp(a, mod - 2); }
    modular& operator/=(modular const& b) { return *this *= inverse(b); }
    friend modular operator+(modular a, modular const b) { return a += b; }
    friend modular operator-(modular a, modular const b) { return a -= b; }
    friend modular operator-(modular const a) { return 0 - a; }
    friend modular operator*(modular a, modular const b) { return a *= b; }
    //除法只有在mod是素数可用;
    friend modular operator/(modular a, modular const b) { return a /= b; }
    friend ostream& operator<<(ostream& os, modular const& a) {return os << a.value;}
    friend istream& operator>>(istream& is, modular & a){long long value; is >> value;a.value = 0; a += value;  return is;}
    friend bool operator==(modular const& a, modular const& b) {return a.value == b.value;}
    friend bool operator!=(modular const& a, modular const& b) {return a.value != b.value;}
};


int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    vector<modular> fib(max(n,m) + 1);
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    
    for (int i = 3; i <= max(n,m); i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    modular ans = fib[n] * 2 + fib[m]*2 -2;
    cout << ans.value<< "\n";
    
    
    
    return 0;
}
