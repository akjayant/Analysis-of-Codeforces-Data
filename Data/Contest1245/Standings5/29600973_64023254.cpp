#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

std::default_random_engine generator;
int rnd(int l, int r)
{
    std::uniform_int_distribution<int> distribution(l, r);
    return distribution(generator);
}

template<class T> inline T gcd(T a, T b)
{
    if(a < 0) return gcd(-a, b);
    if(b < 0) return gcd(a, -b);
    return (b==0) ? a : gcd(b, a%b);
}

template<class T> inline T lcm(T a, T b)
{
    return a / gcd(a, b) * b;
}

const long long mod = 1e9+7;
const double pi = 3.141592653589793238462643383279;

long long powmod(long long x, long long p)
{
    if(p == 0)
        return 1;
    if(p&1)
        return x * powmod(x*x%mod, p/2) % mod;
    else
        return powmod(x*x%mod, p/2) % mod;
}

class Dsu {
public:
    vector<int> p;
    int n;
    
    Dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    
    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(12);
    cout << fixed;
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = int(s.size());
    vector<long long> dp(n);
    if (s[0] == 'm' || s[0] == 'w') {
        cout << "0\n";
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << "0\n";
            return 0;
        }
        dp[i] = dp[i-1];
		if ((s[i] == 'n' && s[i-1] == 'n') ||
            (s[i] == 'u' && s[i-1] == 'u')) {
            if (i > 1)
                dp[i] += dp[i-2];
        	else
                ++dp[i];
        }
        dp[i] %= mod;
    }
    cout << dp[n-1] << endl;
    
    return 0;
}
