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

int col[4][maxn];
int f[4][maxn]; 
ll Ans = 0;  
int n;
std::vector<int> v[maxn];
ll ans = INFL;
int step = 0; 
int anss[maxn];
int tmp[maxn];
std::vector<int> res[8];  
int dep[maxn]; 
void dfs(int x,int fa,int id){  
	for(auto d:v[x]){ 
		if(d == fa) continue;
		Ans += col[res[id][step % 3]][d]; 
		tmp[d] = res[id][step % 3];
		step++;
		dfs(d,x,id);
	}
	return;
}
int id;
void solve(){  
	res[1].pb(1); 	res[1].pb(2); 	res[1].pb(3);  
	res[2].pb(1); 	res[2].pb(3); 	res[2].pb(2);  
	res[3].pb(2); 	res[3].pb(1); 	res[3].pb(3);  
	res[4].pb(2); 	res[4].pb(3); 	res[4].pb(1);  
	res[5].pb(3); 	res[5].pb(2); 	res[5].pb(1);   
	res[6].pb(3); 	res[6].pb(1); 	res[6].pb(2);    
	fr1(i,1,6) {      
		step = 0;
		Ans = 0; 
		dfs(0,0,i);      
		if(Ans < ans) fr1(j,1,n) anss[j] = tmp[j];  
		ans = min(ans,Ans);
	} 
}
int main()
{  
	ios;  
	cin >> n;  
	fr1(i,1,3) fr1(j,1,n) cin >> col[i][j]; 
	fr1(i,1,n - 1){ 
		int x,y;cin>>x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}   
	fr1(i,1,n) if(v[i].size() > 2) { wt(-1); return 0;  }  

	fr1(i,1,n) if(sz(v[i]) == 1) id = i;	v[0].pb(id);
	solve(); 
	wt(ans); 
	fr1(i,1,n) cout << anss[i] << " ";
	cout << endl;
    return 0; 
}




 

/*#include <bits/stdc++.h>
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
int main()
{  
	ios;  
	cin >> n >> p >> w >> d; 
	int l = 0,r = n;
	while()
    return 0; 
}
*/




