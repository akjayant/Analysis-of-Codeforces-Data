//#include<bits/stdc++.h>
//using namespace std;
//#define ls rt<<1
//#define rs (rt<<1)+1
//#define PI acos(-1)
//#define eps 1e-8
//#define ll long long
//#define fuck(x) cout<<#x<<"     "<<x<<endl;
//typedef pair<int,int> pii;
//const int inf=2e9;
//const int maxn=1e6+10;
//int d[4][2]={1,0,-1,0,0,1,0,-1};
////int lowbit(int x){return x&-x;}
////void add(int x,int v){while(x<=n)bit[x]+=v,x+=lowbit(x);}
////int sum(int x){int ans=0;while(x>=1) ans+=bit[x],x-=lowbit(x);return ans;}
//inline ll read() {
//    ll s = 0,w = 1;
//    char ch = getchar();
//    while(!isdigit(ch)) {
//        if(ch == '-') w = -1;
//        ch = getchar();
//    }
//    while(isdigit(ch))
//        s = s * 10 + ch - '0',ch = getchar();
//    return s * w;
//}
//inline void write(ll x) {
//    if(x < 0)
//        putchar('-'), x = -x;
//    if(x > 9)
//        write(x / 10);
//    putchar(x % 10 + '0');
//}
//int gcd(int x,int y){
//    return y==0?x:gcd(y,x%y);
//}
//char s[maxn],t[maxn];
//vector<int>v;
//
//int main(){
//    int k;
//    k=read();
//    while(k--){
//        v.clear();
//        int n;
//        n=read();
//        scanf("%s %s",s+1,t+1);
//        for(int i=1;i<=n;i++){
//            if(s[i]!=t[i])
//                v.push_back(i);
//
//        }
//        if(v.size()==2){
//            if(s[v[0]]==s[v[1]])
//            {
//                puts("YES");
//            } else
//                puts("NO");
//        } else
//            puts("NO");
//    }
//
//    return 0;
//}
//
//#pragma GCC optimize("O3", "unroll-loops")
//#pragma GCC target("avx2")
#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define all(a) a.begin(), a.end()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
#define enter putchar('\n')
#define space putchar(' ')
#define Mem(a, x) memset(a, x, sizeof(a))
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void debug_out() { cerr << '\n'; }

template<typename T, typename ...R>
void debug_out(const T &f, const R &...r) {
    cerr << f << " ";
    debug_out(r...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__);

inline ll read() {
    ll x = 0;
    int f = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') f |= (ch == '-'), ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    return x = f ? -x : x;
}

inline void write(ll x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static char s[23];
    int l = 0;
    while (x != 0)s[l++] = x % 10 + 48, x /= 10;
    while (l)putchar(s[--l]);
}

int lowbit(int x) { return x & (-x); }

template<class T>
T big(const T &a1, const T &a2) { return a1 > a2 ? a1 : a2; }

template<typename T, typename ...R>
T big(const T &f, const R &...r) { return big(f, big(r...)); }

template<class T>
T sml(const T &a1, const T &a2) { return a1 < a2 ? a1 : a2; }

template<typename T, typename ...R>
T sml(const T &f, const R &...r) { return sml(f, sml(r...)); }

template<class T, class U>
inline void checkMin(T &x, U y) { if (y < x) x = y; }

template<class T, class U>
inline void checkMax(T &x, U y) { if (y > x) x = y; }

template<class T, class U>
inline bool ifMax(T &x, U y) {
    if (y > x) return x = y, true;
    return false;
}

template<class T, class U>
inline bool ifMin(T &x, U y) {
    if (y < x) return x = y, true;
    return false;
}

const int M = 212345;// 2e5+5
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;// 1e9+7

// HAVE FREE OPEN IN MAIN FUNCTION

int n;
int a[M];

void init() {
    int _=read();
    while (_--){
        n=read();
        for(int i=0;i<n;i++)a[i]=read();
        sort(a,a+n);
        int ans=0;

        for(int i=0;i<n;i++){
            checkMax(ans,sml(n-i,a[i]));
        }
        write(ans),enter;
    }
    int adf=345;
    int aa=544;
    aa++;
}

void solve() {
int adf=345;
int aa=544;
aa++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();

    solve();

    return 0;
}
