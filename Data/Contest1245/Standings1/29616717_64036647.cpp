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

//char C[100008];

//ll P[100008];



const int limit  =11;
int H[limit][limit];
int A[limit][limit];
int ind[limit*limit][2];
int adj[limit*limit];

long double P[limit*limit];

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
    //    scanf("%s", C + 1);
     //   int n = strlen(C + 1);

      //    scanf("%d",&n);
      int n = 10;
      int k = 0;
          for(int i = 0; i<n;++i){
              for(int j=0; j<n;++j) {
                  if (i & 1) {
                      k = i * n + n - j - 1;
                  } else {
                      k = i * n + j;
                  }
                  A[i][j] = k;
                  scanf("%d", &H[i][j]);
                  ind[k][0] = i;
                  ind[k][1] = j;

                  if (H[i][j] > 0) {
                      adj[k] = A[i - H[i][j]][j];
                  } else
                      adj[k] = -1;

              }

          }


       P[0]=0;
          long double p1=1./6;
       for(int i = 1;i<6;++i){
           long double pre = 0;
           for(int j = 0; j<i;++j)
               pre+=P[j];
           P[i] =     (6+ pre)  /(6- (6-i));
       }
       int top = n*n-1;

        for(int i = 6;i<=top;++i){

            long double pre = 0;
            for(int j = i-6; j<i;++j){
                if(adj[j]>=0){
                    if(P[adj[j]]<P[j])
                        pre+=P[adj[j]];
                    else
                        pre+=P[j];

                } else
                    pre+=P[j];
            }
            P[i]=(6+pre)/6;
        }


        printf("%.10Lf\n",P[top]);

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