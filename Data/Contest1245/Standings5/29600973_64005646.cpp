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
    
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        string res(n, 'o');
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                if (b > 0) {
                    --b;
                    res[i] = 'P';
                }
            } else if (s[i] == 'P') {
                if (c > 0) {
                    --c;
                    res[i] = 'S';
                }
            } else {
                if (a > 0) {
                    --a;
                    res[i] = 'R';
                }
            }
        }
        if (a + b + c <= n/2) {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i) {
                if (res[i] == 'o') {
                    if (a > 0) {
                        --a;
                        cout << 'R';
                    } else if (b > 0) {
                        --b;
                        cout << 'P';
                    } else {
                        --c;
                        cout << 'S';
                    }
                } else
                    cout << res[i];
            }
            cout << '\n';
        } else
            cout << "No\n";
    }
    
    return 0;
}
