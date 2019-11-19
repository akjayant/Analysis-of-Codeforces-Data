#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
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

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(12);
    cout << fixed;
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                mx = max(mx, i);
                mx = max(mx, n - 1 - i);
            }
        }
        if (mx == -1)
            cout << n << endl;
        else
            cout << 2*(mx + 1) << endl;
    }
    
    return 0;
}
