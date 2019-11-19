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

const int N = 1005;

char s[N];

int main() {
    // freopen("data.in", "r", stdin);
    int cas, n;
    read(cas);
    while(cas--) {
        read(n);
        scanf("%s", s + 1);
        int mx = -1, mn = n + 1, ans = n;
        rep(i, 1, n) if(s[i] == '1') {
            tomax(mx, i);
            tomin(mn, i);
        }
        if(mx != -1) tomax(ans, mx * 2);
        if(mn != n + 1) tomax(ans, (n - mn + 1) * 2);
        printf("%d\n", ans);
    }
    return 0;
}
