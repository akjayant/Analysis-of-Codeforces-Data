/* 



 

#include <bits/stdc++.h>
#include <time.h>
#define fi first
#define se second
#define endll "\n"
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define rg(a,x,y) (a+x), (a+y+1)
#define vrg(a,x,y) (a.begin()+x),(a.begin()+y+1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define _sum(a) accumulate(a, 0ll)
#define _max(a,b) *max_element(a,b)
#define pb push_back
#define pr make_pair
#define bugc(_) cerr << (#_) << " = " << (_) << endl; 
#define sz(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define fr1(i,a,b) for (register int i=(a); i<=(b); i++)
#define fr2(i,a,b) for (register int i=(a); i>=(b); i--)
#define ios  ios::sync_with_stdio(false);
#define lson l,mid,rt << 1
#define rson mid + 1,r,rt << 1 | 1
#define times int ttt; cin >> ttt;while(ttt--)
///vector(len,val);
using namespace std;

typedef long long ll;
typedef double db;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
const double eps = 1e-9;
typedef pair<int,int>  P;
typedef pair<ll,ll>  Pl;
typedef pair<double,double>  PP;
const int maxn = 2e6 + 5000;
const ll mod = 1e9 + 7;
const int INF(0x3f3f3f3f);
const ll INFL(0x3f3f3f3f3f3f3f3fll);
inline int sign(db a) { return a < -eps ? -1 : a > eps;}
//inline int cmp(db a,db b){ return sign(a - b);}

ll mul(ll a,ll b,ll c) { ll res = 1; while(b) {  if(b & 1) res *= a,res %= c;  a *= a,a %= c,b >>= 1;  }  return res;}
ll mulll(ll a,ll b,ll c) { ll res = 1; while(b) {  if(b & 1) res *= a,res %= c;  a *= a,a %= c,b >>= 1;  }  return res;}
ll phi(ll x) {  ll res = x;  for(ll i = 2; i * i <= x; i++) { if(x % i == 0) res = res / i * (i - 1);   while(x % i == 0) x /= i;   }  if(x > 1) res = res / x  * (x - 1);    return res;}
template <typename A, typename B> inline bool chmin(A &a, B b){if(a > b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline bool chmax(A &a, B b){if(a < b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline ll add(A x, B y) {if(x + y < 0) return x + y + mod; return x + y >= mod ? x + y - mod : x + y;}
template <typename A, typename B> inline void add2(A &x, B y) {if(x + y < 0) x = x + y + mod; else x = (x + y >= mod ? x + y - mod : x + y);}
template <typename A, typename B> inline ll mul1(A x, B y) {return 1ll * x * y % mod;} /// x * y % mod;
template <typename A, typename B> inline void mul2(A &x, B y) {x = (1ll * x * y % mod + mod) % mod;} /// return x * y
template <typename A> inline void debug(A a){cout << a << '\n';}
template <typename A> inline ll sqr(A x){return 1ll * x * x;}
template <typename A> A inv(A x) {return mulll(x, mod - 2,mod);}
template <typename A> void bugl(A a[],int l,int r) { for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl;  }
template <typename A> void bug(A a[],int l,int r) { for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl;  }
template<class T>void wt(const T& x){cout << x << endl;}
template<class T>void wt(const T& x, char c){cout << x << c;}
template<class T>void wt(const T& x, const string& s){cout << x << s;}
template<class T>void wt(const T& x, int rnd){  cout << fixed << setprecision(rnd) << x << endl;}
template<class T> inline void read(T &x){  x=0; char c=getchar(); int f=1;  while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();} while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;}
inline ll lowbit(ll x){ return (x & (-x)); }
inline void debug(){  cout << "###!!!" << endl;}
//inline void bugl(int a[],int l,int r){ for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl; }
//inline void bug(int a[],int l,int r){ for(int i = l;i <= r;i++) cout << a[i] << " ";  }
ll n,k;
ll a[maxn];
ll p,w,d; 
ll exgcd(ll a, ll b, ll &x, ll &y)  
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}
ll erfen(ll x,ll y){ 
	ll l = 0,r = n,ans = 0;
	while(l <= r){ 
		ll mid = l + r >> 1;
		if(mid * w > y) r = mid - 1; 
		else  l = mid + 1,ans = mid;
	}
	return ans;
}
int main()
{  
	ios;  
	/// p 总分 w赢的分数 d 为 平ju分数
	cin >> n >> p >> w >> d; 
	ll l = 0,r = n;
	while(l <= r){ 
		ll mid = l + r >> 1;
		if(mid * d > p) {r = mid - 1; continue;}
		ll ww = erfen(n - mid,p - mid * d);   

	}
    return 0; 
}


*/


#include <bits/stdc++.h>
#include <time.h>
#define fi first
#define se second
#define endll "\n"
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define rg(a,x,y) (a+x), (a+y+1)
#define vrg(a,x,y) (a.begin()+x),(a.begin()+y+1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define _sum(a) accumulate(a, 0ll)
#define _max(a,b) *max_element(a,b)
#define pb push_back
#define pr make_pair
#define bugc(_) cerr << (#_) << " = " << (_) << endl; 
#define sz(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define fr1(i,a,b) for (register int i=(a); i<=(b); i++)
#define fr2(i,a,b) for (register int i=(a); i>=(b); i--)
#define ios  ios::sync_with_stdio(false);
#define lson l,mid,rt << 1
#define rson mid + 1,r,rt << 1 | 1
#define times int ttt; cin >> ttt;while(ttt--)
///vector(len,val);
using namespace std;

typedef long long ll;
typedef double db;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
const double eps = 1e-9;
typedef pair<int,int>  P;
typedef pair<ll,ll>  Pl;
typedef pair<double,double>  PP;
const int maxn = 2e6 + 5000;
const ll mod = 1e9 + 7;
const int INF(0x3f3f3f3f);
const ll INFL(0x3f3f3f3f3f3f3f3fll);
inline int sign(db a) { return a < -eps ? -1 : a > eps;}
//inline int cmp(db a,db b){ return sign(a - b);}

ll mul(ll a,ll b,ll c) { ll res = 1; while(b) {  if(b & 1) res *= a,res %= c;  a *= a,a %= c,b >>= 1;  }  return res;}
ll mulll(ll a,ll b,ll c) { ll res = 1; while(b) {  if(b & 1) res *= a,res %= c;  a *= a,a %= c,b >>= 1;  }  return res;}
ll phi(ll x) {  ll res = x;  for(ll i = 2; i * i <= x; i++) { if(x % i == 0) res = res / i * (i - 1);   while(x % i == 0) x /= i;   }  if(x > 1) res = res / x  * (x - 1);    return res;}
template <typename A, typename B> inline bool chmin(A &a, B b){if(a > b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline bool chmax(A &a, B b){if(a < b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline ll add(A x, B y) {if(x + y < 0) return x + y + mod; return x + y >= mod ? x + y - mod : x + y;}
template <typename A, typename B> inline void add2(A &x, B y) {if(x + y < 0) x = x + y + mod; else x = (x + y >= mod ? x + y - mod : x + y);}
template <typename A, typename B> inline ll mul1(A x, B y) {return 1ll * x * y % mod;} /// x * y % mod;
template <typename A, typename B> inline void mul2(A &x, B y) {x = (1ll * x * y % mod + mod) % mod;} /// return x * y
template <typename A> inline void debug(A a){cout << a << '\n';}
template <typename A> inline ll sqr(A x){return 1ll * x * x;}
template <typename A> A inv(A x) {return mulll(x, mod - 2,mod);}
template <typename A> void bugl(A a[],int l,int r) { for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl;  }
template <typename A> void bug(A a[],int l,int r) { for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl;  }
template<class T>void wt(const T& x){cout << x << endl;}
template<class T>void wt(const T& x, char c){cout << x << c;}
template<class T>void wt(const T& x, const string& s){cout << x << s;}
template<class T>void wt(const T& x, int rnd){  cout << fixed << setprecision(rnd) << x << endl;}
template<class T> inline void read(T &x){  x=0; char c=getchar(); int f=1;  while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();} while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;}
inline ll lowbit(ll x){ return (x & (-x)); }
inline void debug(){  cout << "###!!!" << endl;}
//inline void bugl(int a[],int l,int r){ for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl; }
//inline void bug(int a[],int l,int r){ for(int i = l;i <= r;i++) cout << a[i] << " ";  }
ll n,k;
ll a[maxn];
ll ans[maxn];
int main()
{  
	ios; 
	while(cin >> n >> k){ 
		fr1(i,1,n) ans[i] = i; 
		ll sum = n * (n + 1) / 2; 
		ll cnt = k - sum;
		if(sum > k) {wt(-1); continue;} 
		fr2(i,n,(n + 2) / 2){  
			if(i - (n - i + 1) <= cnt)  cnt -= (i - (n - i + 1)) ,swap(ans[i],ans[n - i + 1]);
			else {  
				swap(ans[i],ans[i - cnt]);
				cnt = 0;
				break;
			}
		} 
		wt(k - cnt);
		fr1(i,1,n) cout << i << " "; cout << endl;
		fr1(i,1,n) cout << ans[i] << " "; cout << endl;
	}
    return 0; 
}





