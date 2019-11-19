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
    
    long long n, p, w, d;
    cin >> n >> p >> w >> d;
    long long g = gcd(w, d);
    if (p % g != 0) {
        cout << -1 << endl;
        return 0;
    }
    w /= g;
    d /= g;
    p /= g;
    long long rwd = w % d;
    long long rdw = d % w;
    long long rpd = p % d;
    long long rpw = p % w;
    long long x = 1, y = 1;
    for (long long i = 0; i < d; ++i)
        if (i * rwd % d == rpd) {
            x = i;
            break;
        }
    for (long long i = 0; i < w; ++i)
        if (i * rdw % w == rpw) {
            y = i;
            break;
        }
    if (x*w + y*d > p) {
        cout << -1 << endl;
        return 0;
    }
    x += (p - x*w - y*d) / w;
    if (x + y > n) {
        cout << -1 << endl;
        return 0;
    }
    cout << x << ' ' << y << ' ' << n - x - y << endl;
    
    return 0;
}
