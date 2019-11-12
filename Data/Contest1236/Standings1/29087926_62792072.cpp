#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <complex>
#include <bitset>

using namespace std;
using ll=long long int;

template <typename T>
T powint(T a, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1) ret *= a; 
        a *= a;
        n >>= 1;
    }
    return ret;
}

template <ll mod>
class ModInt {
private:
    ll num;
public:
    ModInt() {};
    ModInt(ll n) { num = n % mod; }
    ModInt inv() const { return powint(*this, mod-2); }
    explicit operator ll() const { return num; }

    ModInt& operator+=(const ModInt& a) {
        num += a.num; 
        if (num >= mod) num -= mod; 
        return *this;
    }
    ModInt& operator-=(const ModInt& a) {
        if (num < a.num) num += mod;
        num -= a.num;
        return *this;
    }
    ModInt& operator*=(const ModInt& a) {
        num = num * a.num % mod;
        return *this;
    }
    ModInt& operator/=(const ModInt& a) { return *this *= a.inv(); }
    friend ModInt operator+(const ModInt& a, const ModInt& b) { return ModInt(a) += b; }
    friend ModInt operator-(const ModInt& a, const ModInt& b) { return ModInt(a) -= b; }
    friend ModInt operator*(const ModInt& a, const ModInt& b) { return ModInt(a) *= b; }
    friend ModInt operator/(const ModInt& a, const ModInt& b) { return ModInt(a) /= b; }

    friend ostream& operator<<(ostream& os, const ModInt& a) { return os << a.num; }
    friend istream& operator>>(istream& is, ModInt& a) {
        ll tmp;
        is >> tmp;
        a.num = tmp % mod;
        return is;
    }
};
using mint = ModInt<1000000007>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    mint t = powint(powint((mint)2, m)-1, n);
    cout << t << endl;


    return 0;
}
