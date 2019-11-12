#include <bits/stdc++.h>

#define fr(i, n)    for(int i=0; i<(int)n; ++i)
#define rfr(i, n)   for(int i=(int)n-1; i>=0; --i)
#define foor(i,a,n) for(int i=a; i<=(int)n; ++i)
#define rfoor(i,n,a)for(int i=(int)n; i>=a; --i)
#define foru(it, v) for(auto it : v)
#define si(n)       scanf("%d", &n)
#define si2(n,m)    scanf("%d%d", &n, &m)
#define si3(n,m,l)  scanf("%d%d%d", &n, &m, &l)
#define sl(n)       scanf("%lld", &n)
#define sl2(n,m)    scanf("%lld%lld", &n, &m)
#define sl3(n,m,l)  scanf("%lld%lld%lld", &n, &m, &l)
#define sd(n)       scanf("%lf", &n)
#define sld(n)      scanf("%Lf", &n)
#define sc(n)       scanf(" %c", &n)
#define sstr(n)     scanf("%s", n)
#define pi(n)       printf("%d\n", n)
#define pis(n)      printf("%d ", n)
#define pi2(n,m)    printf("%d %d\n", n, m)
#define pi3(n,m,l)  printf("%d %d %d\n", n, m, l)
#define pl(n)       printf("%lld\n", n)
#define pls(n)      printf("%lld ", n)
#define pl2(n,m)    printf("%lld %lld\n", n, m)
#define pl3(n,m,l)  printf("%lld %lld %lld\n", n, m, l)
#define pc(n)       printf("%c", n)
#define pstr(n)     printf("%s\n", n)
#define pstr2(n, m) printf("%s %s\n", n, m)
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
#define sz(v)       (int)v.size()
#define pub         push_back
#define pob         pop_back()
#define mmst(a, n)  memset(a, n, sizeof a);
#define ppcnt(n)    __builtin_popcount(n);
#define leadingZ(n) __builtin_clz(n)
#define trailingZ(n)__builtin_ctz(n)
#define OO          0x3f3f3f3f
#define OOLL        0x3f3f3f3f3f3f3f3f
#define MOD         1000000007
#define EPS         0.000000001
#define ndl         "\n"
#define fastin      ios::sync_with_stdio(false); cin.tie(nullptr);
#define infile      freopen("input.txt", "r", stdin);
#define outfile     freopen("output.txt", "w", stdout);
#define PNO         printf("NO\n")
#define PYES        printf("YES\n")
#define pno         printf("No\n")
#define pyes        printf("Yes\n")
#define pln         printf("\n")

//#define row         vector<long long>
//#define matrix      vector<row>
//#define ROWS(v)     (v).size()
//#define COLS(v)     (v)[0].size()

//#define NOT(x)  ((x) ^ 1)

#define DBG1(x)     cerr<<#x<<":"<<(x)<<'\n';
#define DBG2(x, y)  cerr<<#x<<":"<<(x)<<"  "<<#y<<":"<<(y)<<'\n';
#define DBG3(x,y,z) cerr<<#x<<":"<<(x)<<"  "<<#y<<":"<<(y)<<"  "<<#z<<":"<<(z)<<'\n';

using namespace std;

typedef long long lld;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<long long , long long>> vpll;
typedef complex<double> point;

const int N = 2e5 + 9;

int t, n, m, k;

lld power(lld b, lld po, lld mod){
    b %= mod;
    lld ret = 1;
    while(po){
        if(po & 1) ret = (ret * b) % mod;
        b = (b * b) % mod;
        po >>= 1;
    }
    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //fastin;
    lld n, m;
    sl2(n, m);
    lld ans = power(2, m, MOD) - 1;
    ans = power(ans, n, MOD);
    pl(ans);
    return 0;
}
