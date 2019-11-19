#include <bits/stdc++.h>
#define File(_) freopen(#_ ".in", "r", stdin), freopen(#_ ".out", "w", stdout)
#define ALL(x) x.begin(), x.end()
#define mset(a, b) memset(a, b, sizeof a)
#define rep(i, a, b) for(int i(a), i##_END_(b); i <= i##_END_; i++)
#define drep(i, a, b) for(int i(a), i##_END_(b); i >= i##_END_; i--)
using namespace std;
template<class T> inline bool tomax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> inline bool tomin(T &a, T b) {return b < a ? a = b, 1 : 0;}
typedef long long ll;
typedef double db;

template<class T>
void read(T &a) {
    char c; bool f = false;
    for(c = getchar(); !isdigit(c); c = getchar()) f |= (c == '-');
    for(a = 0; isdigit(c); c = getchar()) a = (a << 1) + (a << 3) + c - '0';
    if(f) a = -a;
}

template<int N, int M, class T> struct Link {
#define erep(k, G, o) for(int k(G.HEAD[o]); k; k = G.NXT[k])
    int HEAD[N], NXT[M], tot; T W[M];
    void add(int x, T w) {NXT[++tot] = HEAD[x]; W[HEAD[x] = tot] = w;}
    T& operator[] (int k) {return W[k];}
};

int main() {
    int cas, a, b, c, d, k;
    read(cas);
    while(cas--) {
        read(a); read(b); read(c); read(d); read(k);
        int t1 = (a + c - 1) / c, t2 = (d + b - 1) / d;
        if(t1 + t2 > k) puts("-1");
        else printf("%d %d\n", t1, t2);
    }
    return 0;
}
