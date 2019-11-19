#include <bits/stdc++.h>
using namespace std;
void debug() { cout << endl; }
template <class T, class ...R> void debug (T f, R ...r) { cout << "[" << f << "]"; debug (r...); }
template <class T> T mmin(T a, T b) { return min(a,b); }
template <class T, class ...R> T mmin(T a, R... b) { return min(a,mmin(b...)); }
template <class T> T mmax(T a, T b) { return max(a,b); }
template <class T, class ...R> T mmax(T a, R... b) { return max(a,mmax(b...)); }
template <class T> T mgcd(T a, T b) { return __gcd(a,b); }
template <class T, class ...R> T mgcd(T a, R... b) { return __gcd(a,mgcd(b...)); }

void myin()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
}

namespace IO
{
const int MX = 4e7;
char buf[MX];
int c, sz;
void begin()
{
    c = 0;
    sz = fread(buf, 1, MX, stdin);
}
inline bool read(int &t)
{
    while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
    if(c >= sz) return false;
    bool flag = 0;
    if(buf[c] == '-') flag = 1, c++;
    for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
    if(flag) t = -t;
    return true;
}
}

#define ll long long
#define _p pair<ll, ll>
#define all(x) x.begin(), x.end()
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define fi first
#define se second

const ll N = 100005;
const ll M = 1e5+5;
const ll mod = 1e9+7;
// wb  12

char s[505];
int n, ans = 0;

int check() {
    int fq = 0, minn = 1e9;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '(') ++fq;
        else --fq;
        minn = min(minn, fq);
    }
    if(fq) return 0;

    int cnt = 0;
//    if(minn >= 0) cnt = 1;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '(') --minn;
        else ++minn;
        if(minn == 0) ++cnt;
    }
    return cnt;
}

int main() {
    scanf("%d%s",&n,s+1);
    int al = 1, ar = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            swap(s[i],s[j]);
            int tmp = check();
            if(tmp > ans) {
                ans = tmp;
                al = i, ar = j;
            }
            swap(s[i],s[j]);
        }
    }
    printf("%d\n%d %d\n",ans,al,ar);
    return 0;
}

/*
)(()(()())()

)(())()()(()


))()((

*/














