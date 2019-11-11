/*************
 
      /\
     / \
    /AC\
   /   \
 
*************/


//#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
//#pragma GCC target ("sse4")

#include <bits/stdc++.h>

/*** TEMPLATE START ***/
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif
using namespace std;

typedef vector<string> vs;
typedef complex<double> pnt;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


#define SZ(x) ((ll) (x).size())

#define pb push_back
#define mp make_pair
#define eb emplace_back

#define fi first
#define se second


typedef tuple<int, int, int> t3;

typedef double db;
typedef long double ldb;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;

int IT_MAX = 1 << 17;

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;


mt19937 mrand(random_device{}());

int rnd(int x) { return mrand() % x; }


template<class T>
void splitstr(const string &s, vector<T> &out) {
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

template<class T>
inline T pow_mod(T p, T e, T M) {
    T ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T) ret;
}

template<class T>
inline T modinverse(T a, T M) { return pow_mod(a, M - 2, M); }

template<class T>
inline T lcm(T a, T b) {
    a = abs(a);
    b = abs(b);
    return (a / gcd(a, b)) * b;
}

template<class T, class X>
inline bool getbit(T a, X i) {
    T t = 1;
    return ((a & (t << i)) > 0);
}

template<class T, class X>
inline T setbit(T a, X i) {
    T t = 1;
    return (a | (t << i));
}

template<class T, class X>
inline T resetbit(T a, X i) {
    T t = 1;
    return (a & (~(t << i)));
}


//#define endl '\n';

/*** TEMPLATE ENDS ***/






ll pow_mod(ll a, ll p, ll mod) { //a^p % mod
    ll res = 1;
    a %= mod;
    while (p > 0) {
        if (p & 1) {
            //res = mul_mod(res, a, mod);
            res = res * a % mod;
        }
        p >>= 1;
        //a = mul_mod(a,a,mod);
        a = a * a % mod;
    }
    return res;
}

/*
 *
 *
 *
 
 */



int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

char C[100008];

ll P[100008];
const ll mod = 1e9 + 7;

void solve() {
//int n, m,h;
    //       scanf("%d %d %d", &n, &m,&h);
    int t, m, k;
    int a, b, c, n;

    t = 1;

    //  scanf("%d", &n);
    //  scanf("%d",&t);

    while (t--) {
        //   scanf("%d",&n);


        //  scanf("%d %d %d", &a, &b,&c);
        scanf("%s", C + 1);
        int n = strlen(C + 1);
        C[0] = '#';
        C[n + 1] = '#';
        C[n + 2] = '\0';
        unordered_map<int, int> mp;
        int cnt = 0;
        int n1 = n + 1;
        int mx = 0;
        for (int i = 1; i <= n1; ++i) {
            if (C[i] == 'w' || C[i] == 'm') {
                printf("0\n");
                return;
            }
            if (C[i] == C[i-1] ) {
                if (C[i] == 'u' || C[i] == 'n')
                    cnt++;
                else
                    cnt = 0;
            } else {
                if (cnt) {
                    mp[cnt]++;
                    if (cnt > mx)
                        mx = cnt;
                }
                if (C[i] == 'u' || C[i] == 'n')
                    cnt = 1;
                else
                    cnt = 0;
            }
        }


        P[0] = 1;
        P[1] = 1;
        for (int i = 2; i <= mx; ++i) {
            P[i] = P[i - 1] + P[i - 2];
            if (P[i] >= mod)
                P[i] -= mod;
        }

        ll res = 1;
        for (auto a:mp) {
            if (a.first > 1)
                res = res * pow_mod(P[a.first], a.second, mod) % mod;
        }


        printf("%lld\n", res);


    }


}


int main() {
// ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    clock_t beg = clock();

    solve();


    //   clock_t end = clock();
//fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
}