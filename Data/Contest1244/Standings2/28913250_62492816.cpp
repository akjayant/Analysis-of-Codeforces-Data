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

const int N = 1e5 + 5;

int a[N], cnt[N];

int main() {
    int n;
    ll k;
    read(n); read(k);
    rep(i, 1, n) read(a[i]);
    sort(a + 1, a + 1 + n);
    int tot = 0;
    rep(i, 1, n) {
        if(i == 1 || a[i] != a[i - 1]) {
            a[++tot] = a[i];
            cnt[tot] = 1;
        }
        else cnt[tot]++;
    }
    n = tot;
    int l = 1, r = n;
    while(l < r) {
        if(k < min(cnt[l], cnt[r])) break;
        if(cnt[l] < cnt[r]) {
            ll d = (ll) cnt[l] * (a[l + 1] - a[l]);
            if(d <= k) {
                k -= d;
                cnt[l + 1] += cnt[l];
                l++;
            }
            else a[l] += k / cnt[l], k -= (k / cnt[l]) * cnt[l];
        }
        else {
            ll d = (ll) cnt[r] * (a[r] - a[r - 1]);
            if(d <= k) {
                k -= d;
                cnt[r - 1] += cnt[r];
                r--;
            }
            else a[r] -= k / cnt[r], k -= (k / cnt[r]) * cnt[r];
        }
    }
    printf("%d\n", a[r] - a[l]);
    return 0;
}
