#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
 
ifstream fin("input.txt");
ofstream fout("output.txt");
 
bool isPrime(long long int x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (int i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }
 
int NumDigits(int x)
{
    //x = abs(x);
    return (x < 10 ? 1 :
        (x < 100 ? 2 :
        (x < 1000 ? 3 :
        (x < 10000 ? 4 :
        (x < 100000 ? 5 :
        (x < 1000000 ? 6 :
        (x < 10000000 ? 7 :
        (x < 100000000 ? 8 :
        (x < 1000000000 ? 9 :
        10)))))))));
}
 
inline void boostIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cout.precision(10);
}
 
typedef long long int ll;
typedef long double ld;
 
#define fori(n)  for(int i = 0; i < (n); ++i)
#define forj(n)  for(int j = 0; j < (n); ++j)
#define fork(n) for(int k = 0; k < (n); ++k)
#define forx(n) for(int x = 0; x < (n); ++x)
 
//#define LONG_LONG_MAX  9223372036854775807
//#define LONG_LONG_MIN   -9223372036854775807
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
 
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define debug(x) cerr << #x << " " << x << endl;
#define debug_p(x) cerr << #x << " " << x.ff << " " << x.ss << endl;
#define debug_v(x) cerr << #x << " "; for (auto ii : x) cout << ii << " "; cout << endl;
#define debug_vp(x) cerr << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
#define mp make_pair
 
#define Return cerr<<endl<<"RUNTIME: "<<1.0*clock()/CLOCKS_PER_SEC << " s" <<endl; return 0;
 
#define PI 3.14159265
 
ll Pow10[19] = {(ll)1,(ll)1e1,(ll)1e2,(ll)1e3,(ll)1e4,(ll)1e5,(ll)1e6,(ll)1e7,(ll)1e8,(ll)1e9,(ll)1e10,
                (ll)1e11,(ll)1e12,(ll)1e13,(ll)1e14,(ll)1e15,(ll)1e16,(ll)1e17,(ll)1e18};
 
//int mid = low + ((high - low) / 2);
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b);}
 
 /*
struct Mine {
    int g = 0;
    int x = 0;
    int y = 0;
    int X = 0;
    int Y = 0;
};
/
struct comp {
    bool operator()(Mine const & a, Mine const & b) {
        return a.g >= b.g;
    }
};
set<Mine, comp> Set;
*/
 
//__builtin_clz(int); amount of 0 in the begining
//__builtin_ctz(int); amoint of 0 in the end
//__builtin_popcount(int); amount of 1
 
//memset(dp, -1, sizeof dp);
 
/////////////////////
#define int long long
int Mod = 1e9 + 7;
#define endl '\n'
////////////////////
 
template <class T> struct Fenwick {
    vector<T> V;
    Fenwick(int n): V(n) {}
    void add(size_t i, T x) { for (; i < V.size(); i |= i + 1) V[i] += x; }
    T sum(int i) { T r = T(); for (--i; i >= 0; i = (i & (i + 1)) - 1) r += V[i]; return r; }
    T sum(int l, int r) { return sum(r) - sum(l); }
};
 
int mul(int a, int b, int c = 1, int d = 1, int e = 1, int g = 1){
    a %= Mod; b %= Mod; c %= Mod; d %= Mod; e %= Mod; g %= Mod;
    return (a * b  % Mod * c % Mod * d % Mod * e % Mod * g % Mod);
}
 
int Pow(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 0) {
        int x = Pow(a, b/2);
        return mul(x, x);
    }
    else  {
         int x = Pow(a, b/2);
        return  mul(a, x, x);
    }
}

int32_t main() {
    boostIO();
    int n; cin >> n;
    vector<vector<int>> A(n, vector<int> (n));
    int a = n*n;
    int b = 1;
    
    
    for(int j = 0; j < n; ++j) {
            if(j % 2 == 0) {
                for(int i = 0; i < n; ++i) {
                    A[i][j] = a;
                    --a;
                }
            }
            else {
                fori(n) {
                    A[i][j] = b;
                    ++b;
                }
            }
    }
    fori(n) {
        forj(n) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}