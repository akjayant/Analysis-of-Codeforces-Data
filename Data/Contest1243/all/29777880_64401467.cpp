#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long L, long long R) {
    return L + rd() % (R - L + 1);
}
long long MUL(long long A, long long B, long long MOD) {
    long long r = 0;
    while (B) {
        r = (r + (A * (B % 2) % MOD)) % MOD;
        A = (A + A) % MOD;
        B /= 2;
    }
    return r;
}
long long POW(long long A, long long B, long long MOD) {
    long long RES = 1;
    A %= MOD;
    assert(B >= 0);
    for(; B; B >>= 1) {
        if (B & 1)
            RES = MUL(RES, A, MOD);
        A = MUL(A, A, MOD);
    }
    return RES;
}
long long GCD(long long A, long long B) {
    return B == 0 ? A : GCD(B, A % B);
}
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0,  0, 1, 0,-1};

#define __gcd GCD
#define in ({int x=0,n=0,c=getchar();for(;!isdigit(c);c=getchar())n=(c=='-');for(;isdigit(c);c=getchar())x=x*10+c-'0';(n)?-x:x;})
#define inc ({char c=0;for(;c=='\n'||c==' ';c=getchar());c=getchar();c;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define ii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define db double
#define vi vector <int>
#define vii vector <ii>
#define reset(f, x) memset(f, x, sizeof(f))
#define all(v) v.begin(), v.end()
#define bit(mask, i) (mask & (1ll << i))
#define onbit(mask, i) (mask | (1ll << i))
#define offbit(mask, i) (mask &~ (1ll << i))
#define sz(v) (int) v.size()
#define bug1(a) cout << #a << " = " << a << ";"
#define bug1l(a) cout << #a << " = " << a << ";" << '\n'
#define bug2(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << "; "
#define bug2l(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << '\n'
#define bug3(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; "
#define bug3l(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << '\n'
#define bug4(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << #d << " = " << d << "; "
#define bug4l(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << ";" << #c << " = " << c << "; " << #d << " = " << d << "; " << '\n'
#define FASTIOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TASK "1243d"
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Ford(a,b,c) for(int a=b;a>=c;--a)
#define Fv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define vt vector<int>
#define vpi vector<pair<int,int>>
#define sz(x) (int)(x.size())
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>i&1ll)
#define on(x,i) (x|(1ll<<i))
#define off(x,i) (x&~(1ll<<i))
#define int long long
const int MAXN=1e5+5;
int n,GGGGGG[MAXN], vis[MAXN], HHH[MAXN], m, d, MMMCNT;
vector<int> LLOIJJDJFFHDSHAFHAFHSHG[MAXN], gr[MAXN];
vpi E;
int GOCGOCGOC(int x) {
    return GGGGGG[x]==x?x:GGGGGG[x]=GOCGOCGOC(GGGGGG[x]);
}
void bfs(int s) {
    queue <int> q;
    q.push(s);
    GGGGGG[s]=GOCGOCGOC(s+1);
    gr[MMMCNT].push_back(s);
    HHH[s]=MMMCNT;
    while(!q.empty()) {
        int x=q.front();
        q.pop();
        Fv(v,LLOIJJDJFFHDSHAFHAFHSHG[x]) {
            vis[v]=x;
        }
        for(int i=GOCGOCGOC(1); i <= n; i = GOCGOCGOC(i + 1)) {
            if(vis[i]!=x)
                GGGGGG[i]=GOCGOCGOC(i+1),q.push(i),gr[MMMCNT].push_back(i),HHH[i]=MMMCNT;
        }
    }
    ++MMMCNT;
}
string PLUFHHF[MAXN];

void upd(int i, char c, int GGGGGG) {
    Fv(v,gr[i])PLUFHHF[GGGGGG][v-1]=c;
}

void sfjsafjsahfhafh(int x,int GGGGGG) {
    d=max(GGGGGG,d);
    if (x == 1|| x == 2)
        return;
    sfjsafjsahfhafh(x/2, GGGGGG + 1);
    sfjsafjsahfhafh(x - x / 2, GGGGGG + 1);
}

inline void get(int j, int x, int GGGGGG) {
    if(x == 1) {
        return;
    } else if(x == 2) {
        upd(j + 1, '1', GGGGGG);
    } else {
        int xx = x / 2;
        for(int i = xx ; i < x ; ++i)
            upd(j + i, '1', GGGGGG);
        get(j, xx, GGGGGG + 1);
        get(j + xx, x - xx, GGGGGG + 1);
    }
}

main() {
    FASTIOS;
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u,v;
        cin >> u >> v;
        LLOIJJDJFFHDSHAFHAFHSHG[u].push_back(v);
        LLOIJJDJFFHDSHAFHAFHSHG[v].push_back(u);
    }
    for (int i = 1; i <= n + 1; ++i)
        GGGGGG[i]=i;
    for(int i = 1; i <= n; i=GOCGOCGOC(i+1))
        bfs(i);
    sfjsafjsahfhafh(MMMCNT, 0);
    d++;
    for (int i = 0; i <= n - 1; ++i)
        PLUFHHF[0].push_back('0');

    for (int i = 1; i <= d - 1; ++i)
    PLUFHHF[i]=PLUFHHF[0];
    get(0,MMMCNT,0);
    cout<<MMMCNT-1;
}
