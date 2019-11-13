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
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;





mt19937 mrand(random_device{}());

int rnd(int x) { return mrand() % x;}


template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> inline T pow_mod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T modinverse(T a,T M){return pow_mod(a,M-2,M);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T, class X> inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0);}
template <class T, class X> inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template <class T, class X> inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));}


//#define endl '\n';

/*** TEMPLATE ENDS ***/






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
char C[108];
char C2[108];


void solve() {
//int n, m,h;
    //       scanf("%d %d %d", &n, &m,&h);
    int t,m,k;
    int a,b,c,n;
    //  scanf("%d", &n);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);


        scanf("%d %d %d", &a, &b,&c);
        scanf("%s",C);
        int a1=0,b1=0,c1=0;
        for(int i = 0; i<n;++i)
            if(C[i]=='R')
                a1++;
            else if (C[i]=='P')
                b1++;
            else
                c1++;

            int cnt = 0;
            int cnt1=min(a,c1);
            int cnt2=min(b,a1);
            int cnt3=min(c,b1);
            cnt+=cnt1+cnt2+cnt3;
            if(cnt>= (n+1)/2){
                printf("YES\n");
                memset(C2,0,sizeof C2);
                C2[n]='\0';
                int r1=a-cnt1;
                int r2=b-cnt2;
                int r3=c-cnt3;

                for(int i = 0; i<n;++i)
                    if(C[i]=='R') {
                       if(cnt2){
                           cnt2--;
                           C2[i]='P';
                       }
                       else if(r1){
                           r1--;
                           C2[i]='R';
                       }
                       else{
                           r3--;
                           C2[i]='S';
                       }
                    }
                    else if (C[i]=='P') {
                        if(cnt3){
                            cnt3--;
                            C2[i]='S';
                        }
                        else if(r2){
                            r2--;
                            C2[i]='P';
                        }
                        else{
                            r1--;
                            C2[i]='R';
                        }

                    }
                    else {
                        if(cnt1){
                            cnt1--;
                            C2[i]='R';
                        }
                        else if(r3){
                            r3--;
                            C2[i]='S';
                        }
                        else{
                            r2--;
                            C2[i]='P';
                        }
                    }

                printf("%s\n",C2);


            } else
                printf("NO\n");

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