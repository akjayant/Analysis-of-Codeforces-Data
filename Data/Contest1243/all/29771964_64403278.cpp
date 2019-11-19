#include <bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define RREP(i,n) for(int i=int(n)-1;i>=0;--i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define rrep(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
#define ITR(i,x) for(auto i=(x).begin();i!=(x).end();++i)
using namespace std;
using Graph = vector<vector<int>>;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
constexpr ll mod = 1e9+7;
constexpr double eps = 1e-9;
const double PI = acos(-1);
void solve();

template<typename T>
bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}
template<typename T>
bool chmin(T &a,T b){
    if(b<a){
        a=b;
        return true;
    }
    return false;
}
ll bisearch(ll ok,ll ng,function<bool(ll)> check){
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}
ll SQRT(ll n){ll s=1; while(s*s>n||n>=(s+1)*(s+1)){ s=(n/s+s)/2; } return s;}
ll roundup(ll n,ll div){
    if(n>0) return (n-1)/div+1;
    else return n/div;    
}
bool square(ll a){ll n=SQRT(a);return a==n*n;}
template<typename T> T npow(T x, ll n){
    T ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x;
        x = x*x;
        n = n >> 1;
    }
    return ans;
}
ll mpow(ll x, ll n){
    ll ans = 1; x%=mod;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}
ll inv_mod(ll a){return mpow(a,mod-2);}
int digitsum(ll N,int a){
    if(N==0) return 0;
    int ret=0;
    ret+=digitsum(N/a,a)+N%a;
    return ret;
}
ll gcd(ll x,ll y){return y ? gcd(y,x%y) : x;};
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
void YN(bool flg){std::cout<<(flg?"YES":"NO")<<endl;}
void Yn(bool flg){std::cout<<(flg?"Yes":"No")<<endl;}
void yn(bool flg){std::cout<<(flg?"yes":"no")<<endl;}
ll manhattan(const P &a,const P &b){return llabs(a.first-b.first)+llabs(a.second-b.second);}
template<class V> 
vector<int> Zalgo(V s){
    vector<int> A(s.size(),0);
    A[0]=s.size();
    int i = 1, j = 0;
    while (i < s.size()) {
        while (i+j < s.size() && s[j] == s[i+j]) ++j;
        A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < s.size() && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
    }
    return A;
}
class mint {
 private:
  ll _num,_mod;
  mint set(ll num){ 
      _num = num ;
      if(_num>=0) _num%=_mod;
      else _num+=(1-(_num+1)/_mod)*_mod; 
      return *this;
  }
  ll _mpow(ll x, ll n){ //x^n(mod) ←普通にpow(x,n)では溢れてしまうため，随時mod計算 2分累乗法だから早い
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % _mod;
        x = x*x % _mod;
        n = n >> 1;
    }
    return ans;
  }
  ll imod(ll n){return _mpow(n , _mod-2);}
 public:
  mint(){ _num = 0;_mod=mod; }
  mint(ll num){ _mod = mod; _num = (num+(1LL<<25)*mod) % mod; }
  mint(ll num,ll M){ _mod=M;_num=(num+(1LL<<25)*mod)%_mod; }
  mint(const mint &cp){_num=cp._num;_mod=cp._mod;}
  mint operator= (const ll x){ return set(x); }
  mint operator+ (const ll x){ return mint(_num + (x % _mod) , _mod); }
  mint operator- (const ll x){ return mint(_num - (x % _mod), _mod); }
  mint operator* (const ll x){ return mint(_num * (x % _mod) , _mod); }
  mint operator/ (ll x){ return mint(_num * imod(x) , _mod);}
  mint operator+=(const ll x){ return set(_num + (x % _mod)); }
  mint operator-=(const ll x){ return set(_num - (x % _mod)); }
  mint operator*=(const ll x){ return set(_num * (x % _mod)); }
  mint operator/=(ll x){ return set(_num * imod(x));}
  mint operator+ (const mint &x){ return mint(_num + x._num , _mod); }
  mint operator- (const mint &x){ return mint(_num - x._num , _mod);}
  mint operator* (const mint &x){ return mint(_num * x._num , _mod); }
  mint operator/ (mint x){ return mint(_num * imod(x._num) , _mod);}
  mint operator+=(const mint &x){ return set(_num + x._num); }
  mint operator-=(const mint &x){ return set(_num - x._num); }
  mint operator*=(const mint &x){ return set(_num * x._num); }
  mint operator/=(mint x){ return set(_num * imod(x._num));}

  bool operator<(const mint &x)const{return _num<x._num;}
  bool operator==(const mint &x)const{return _num==x._num;}
  bool operator>(const mint &x)const{return _num>x._num;}

  friend mint operator+(ll x,const mint &m){return mint(m._num + (x % m._mod) , m._mod);}
  friend mint operator-(ll x,const mint &m){return mint( (x % m._mod) - m._num , m._mod);}
  friend mint operator*(ll x,const mint &m){return mint(m._num * (x % m._mod) , m._mod);}
  friend mint operator/(ll x,mint m){return mint(m.imod(m._num) * x , m._mod);}

  explicit operator ll() { return _num; }
  explicit operator int() { return (int)_num; }

  friend ostream& operator<<(ostream &os, const mint &x){ os << x._num; return os; }
  friend istream& operator>>(istream &is, mint &x){ll val; is>>val; x.set(val); return is;}
};
template<typename T> class MAT{
 private:
    int row,col;
    vector<vector<T>> _A;
    MAT set(vector<vector<T>> A){_A = A ; return *this;}
 public:
    MAT(){ }
    MAT(int n,int m){
        if(n<1 || m<0){cout << "err Matrix::Matrix" <<endl;exit(1);}
        row = n;
        col = m?m:n;//m=0のとき単位行列を作る
        REP(i,row){
            vector<T> a(col,0.0);
            _A.push_back(a);
        }
        //  値の初期化
        if(m==0) REP(i,n) _A[i][i]=1.0;
    }
    MAT(const MAT &cp){_A=cp._A;row=cp.row;col=cp.col;}
    T* operator[] (int i){return _A[i].data();}
    MAT operator= (vector<vector<T>> x) {return set(x);}
    MAT operator+ (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator+" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]+x[i][j];
        return r;
    }
    MAT operator- (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator-" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]-x[i][j];
        return r;
    }
    MAT operator* (MAT x) {
        if(col!=x.row){
            cout << "err Matrix::operator*" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, x.col);
        REP(i,row) REP(j,x.col) REP(k,col) r[i][j]+=_A[i][k]*x[k][j];
        return r;
    }
    MAT operator/ (T a){
        MAT r(row,col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]/a;
        return r;
    }
    MAT operator^ (ll n){
        if(row!=col){
            cout << "err Matrix::operator^" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row,0),A=*this;
        while(n){
            if(n&1) r *= A;
            A*=A;
            n>>=1;
        }
        return r;
    }
    MAT operator+= (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator+=" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]+x[i][j];
        return set(r._A);
    }
    MAT operator-= (MAT x) {
        if(row!=x.row || col!=x.col){
            cout << "err Matrix::operator-=" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]-x[i][j];
        return set(r._A);
    }
    MAT operator*= (MAT x) {
        if(col!=x.row){
            cout << "err Matrix::operator*" <<endl;
            cout << "  not equal matrix size" <<endl;
            exit(0);
        }
        MAT r(row, x.col);
        REP(i,row) REP(j,x.col) REP(k,col) r[i][j]+=_A[i][k]*x[k][j];
        return set(r._A);
    }
    MAT operator/=(T a){
        MAT r(row,col);
        REP(i,row) REP(j,col) r[i][j]=_A[i][j]/a;
        return r;
    }

    friend MAT operator* (T n,MAT x){
        MAT r(x.row,x.col);
        REP(i,x.row) REP(j,x.col) r[i][j]=n*x[i][j];
        return r;
    }
    friend MAT operator* (MAT x,T n){
        MAT r(x.row,x.col);
        REP(i,x.row) REP(j,x.col) r[i][j]=n*x[i][j];
        return r;
    }
    explicit operator vector<vector<T>>(){return _A;}
    friend ostream &operator<<(ostream &os,const MAT &x){ REP(i,x.row) REP(j,x.col) os<<x._A[i][j]<<" \n"[j==x.col-1]; return os;}
    friend istream &operator>>(istream &is,MAT &x){REP(i,x.row) REP(j,x.col) is>>x._A[i][j];return is;}
    int size_row(){return row;}
    int size_col(){return col;}
    MAT transpose(){
        MAT r(col,row);
        REP(i,col) REP(j,row) r[i][j]=_A[j][i];
        return r;
    }
    MAT inverse(){
        T buf;
        MAT<T> inv_a(row,0);
        vector<vector<T>> a=_A;
        //掃き出し法
        REP(i,row){
            buf=1/a[i][i];
            REP(j,row){
                a[i][j]*=buf;
                inv_a[i][j]*=buf;
            }
            REP(j,row){
                if(i!=j){
                    buf=a[j][i];
                    REP(k,row){
                        a[j][k]-=a[i][k]*buf;
                       inv_a[j][k]-=inv_a[i][k]*buf;
                    }
                }
            }
        }
        return inv_a;
    }
    // O( n^3 ).
    int rank() {
        vector<vector<T>> A=_A;
        const int n = row, m = col;
        int r = 0;
        for(int i = 0; r < n && i < m; ++i) {
            int pivot = r;
            for(int j = r+1; j < n; ++j) if(fabs(A[j][i]) > fabs(A[pivot][i])) pivot = j;
            swap(A[pivot], A[r]);
            if(fabs(A[r][i]) < eps) continue;
            for (int k = m-1; k >= i; --k) A[r][k] /= A[r][i];
            rep(j,r+1,n) rep(k,i,m) A[j][k] -= A[r][k] * A[j][i];
            ++r;
        }
        return r;
    }
};
class UnionFind{//UnionFind木
 private:
    vector<int> Parent,es;
    vector<ll> diff_weight;
 public:
    UnionFind(int N){
        es.resize(N,0);
        Parent.resize(N,-1);
        diff_weight.resize(N,0LL);
    }

    int root(int A){
        if(Parent[A]<0) return A;
        else{ 
            int r = root(Parent[A]);
            diff_weight[A] += diff_weight[Parent[A]]; // 累積和をとる
            return Parent[A]=r;
        }
    }
    bool issame(int A,int B){
        return root(A)==root(B);
    }
    ll weight(int x) {
        root(x); // 経路圧縮
        return diff_weight[x];
    }
    ll diff(int x, int y) {
        return weight(y) - weight(x);
    }
    int size(int A){
        return -Parent[root(A)];
    }
    int eize(int A){
        return es[root(A)];
    }
    bool connect(int A,int B){
        A=root(A); B=root(B);
        if(A==B) return false;
        if(size(A)<size(B)) swap(A,B);
        Parent[A]+=Parent[B];
        es[A]+=es[B]+1;
        Parent[B]=A;
        return true;
    }
    void unite(int A,int B){
        A=root(A); B=root(B);
        if(A==B){ 
            es[A]++;
            return;
        }
        if(size(A)<size(B)) swap(A,B);
        Parent[A]+=Parent[B];
        es[A]+=es[B]+1;
        Parent[B]=A;
        return;
    }
    bool merge(int A, int B, ll w) {
        // x と y それぞれについて、 root との重み差分を補正
        w += weight(A); w -= weight(B); 
        A=root(A); B=root(B);
        if(A==B) return false;
        if(size(A)<size(B)) swap(A,B),w=-w;
        Parent[A]+=Parent[B];
        Parent[B]=A;
        // x が y の親になるので、x と y の差分を diff_weight[y] に記録
        diff_weight[B] = w; 
        return true;
    }
};
class Factorial{//階乗とその逆元を求めて計算に利用するクラス
 private:
    vector<ll> fac;
    vector<ll> ifac;
 public:
    
    Factorial(ll N){
        fac.push_back(1);
        REP(i,N) fac.push_back(fac[i]*(i+1)%mod);
        ifac.resize(N+1);
        ifac[N]=inv_mod(fac[N]);
        REP(i,N) ifac[N-1-i]=(ifac[N-i]*(N-i))%mod;
    }

    ll fact(ll a){return fac[a];}
    ll ifact(ll a){return ifac[a];}

    ll cmb(ll a,ll b){
        if(a==0&&b==0) return 1;
        if(a<b||a<0||b<0) return 0;
        ll tmp =ifact(a-b)*ifact(b)%mod;
        return tmp*fac[a]%mod;
    }
    ll per(ll a,ll b){
        if(a==0&&b==0) return 1;
        if(a<b||a<0||b<0) return 0;
        return fac[a]*ifac[a-b]%mod;
    }
};
class SOSU{
 private:
    vector<int> Prime_Number;
    vector<bool> isp;
 public:
    SOSU(int N){
        isp.resize(N+1,true);
        isp[0]=isp[1]=false;
        rep(i,2,N+1) if(isp[i]){
            Prime_Number.push_back(i);
            for(int j=2*i;j<=N;j+=i) isp[j]=false;
        }
    }
    int operator[](int i){return Prime_Number[i];}
    int size(){return Prime_Number.size();}
    int back(){return Prime_Number.back();}
    bool isPrime(int q){return isp[q];}
};
class Divisor{//素因数分解をしてから約数列挙、分解結果はＰ(底,指数)でpfacにまとめている
  private:
    vector<ll> F;
    vector<P> pfactorize;
  public:
    Divisor(ll N){
        for(ll i = 1; i * i <= N; i++) {
            if(N % i == 0) {
                F.push_back(i);
                if(i * i != N) F.push_back(N / i);
            }
        }
        sort(begin(F), end(F));
		SOSU p(SQRT(N)+1);
    	REP(i,p.size()){
    		pfactorize.push_back(P(p[i],0));
    		while(N%p[i]==0){
    			N/=p[i];
    			pfactorize.back().second++;
    		}
            if(pfactorize.back().second==0) pfactorize.pop_back();
    	}
    	if(N>1) pfactorize.push_back(P(N,1));
    }
    int size(){return F.size();}
    vector<P> pfac(){return pfactorize;}
    ll operator[](int k){return F[k];}
};
struct compress{
    map<ll,int> zip;
    vector<ll> unzip;
    compress(vector<ll> x){
        unzip=x;
        sort(All(x));
        x.erase(unique(All(x)),x.end());
        REP(i,x.size()){
            zip[x[i]]=i;
        }
    }
    int operator[](int k){return zip[unzip[k]];}
};
struct edge{
    int from;int to;ll cost;
    void push(int a,int b,int c){
        from=a;to=b;cost=c;
    }
    bool operator<(const edge& y) const{
        if(cost!=y.cost) return cost<y.cost;
        else if(to!=y.to) return to<y.to;
        else return from<y.from;}
    bool operator>(const edge& y) const{
        if(cost!=y.cost) return cost>y.cost;
        else if(to!=y.to) return to>y.to;
        else return from>y.from;}
    bool operator==(const edge& y) const{return *this==y;}
};
class lca {
  public:
    const int n = 0;
    const int log2_n = 0;
    std::vector<std::vector<int>> parent;
    std::vector<int> depth;

    lca() {}

    lca(const Graph &g, int root)
        : n(g.size()), log2_n(log2(n) + 1), parent(log2_n, std::vector<int>(n)), depth(n) {
        dfs(g, root, -1, 0);
        for (int k = 0; k + 1 < log2_n; k++) {
            for (int v = 0; v < (int)g.size(); v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void dfs(const Graph &g, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        REP(j,g[v].size()) {
            if (g[v][j] != p) dfs(g, g[v][j], v, d + 1);
        }
    }

    int get(int u, int v) {
        if (depth[u] > depth[v]) std::swap(u, v);
        for (int k = 0; k < log2_n; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = log2_n - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};
template<typename T> class SegmentTree{
  private:
    typedef function<T(T,T)> F;
    int n;
    T d0;
    vector<T> vertex;
    F f;
    F g;
  public:
    SegmentTree(F f,F g,T d):d0(d),f(f),g(g){}
    void init(int _n){
        n=1;
        while(n<_n) n*=2;
        vertex.resize(2*n-1,d0);
    }
    void build(const vector<T> &v){
        int n_=v.size();
        init(n_);
        for(int i=0;i<n_;i++) vertex[n+i-1]=v[i];
        for(int i=n-2;i>=0;i--)
        vertex[i]=f(vertex[2*i+1],vertex[2*i+2]);
    }
    void update(int i,T x){
        int k=i+n-1;
        vertex[k]=g(vertex[k],x);
        while(k>0){
            k=(k-1)/2;
            vertex[k]=f(vertex[2*k+1],vertex[2*k+2]);
        }
        return;
    }
    T query(int l,int r){
        T vl=d0,vr=d0;
        l+=n-1;
        r+=n-1;
        for(;l<=r;l/=2,r=r/2-1){
            if(l%2==0) vl=f(vl,vertex[l]);
            if(r&1) vr=f(vr,vertex[r]);
        }
        return f(vl,vr);
    }
};
template <typename T,typename E>
struct LazySegmentTree{
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  int n,height;
  F f;
  G g;
  H h;
  T ti;
  E ei;
  vector<T> dat;
  vector<E> laz;
  LazySegmentTree(F f,G g,H h,T ti,E ei):
    f(f),g(g),h(h),ti(ti),ei(ei){}
  
  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    dat.assign(2*n,ti);
    laz.assign(2*n,ei);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  inline T reflect(int k){
    return laz[k]==ei?dat[k]:g(dat[k],laz[k]);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    dat[k]=reflect(k);
    laz[k]=ei;
  }
  inline void thrust(int k){
    for(int i=height;i;i--) eval(k>>i);
  }
  inline void recalc(int k){    
    while(k>>=1)
      dat[k]=f(reflect((k<<1)|0),reflect((k<<1)|1));
  }
  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
    recalc(a);
    recalc(b);
  }
  void set_val(int a,T x){
    thrust(a+=n);
    dat[a]=x;laz[a]=ei;
    recalc(a);
  }
  T query(int a,int b){
    thrust(a+=n);
    thrust(b+=n-1);
    T vl=ti,vr=ti;
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,reflect(l++));
      if(r&1) vr=f(reflect(--r),vr);
    }
    return f(vl,vr);
  }
};
struct rational {
  ll p, q;
  void normalize() { // keep q positive
    if (q < 0) p *= -1, q *= -1;
    ll d = gcd(p < 0 ? -p : p, q);
    if (d == 0) p = 0,  q = 1;
    else        p /= d, q /= d;
  }
  rational(ll p, ll q = 1) : p(p), q(q) {
    normalize();
  }
  rational &operator+=(const rational &a){p = a.q * p + a.p * q; q = a.q * q; normalize();return *this;}
  rational &operator-=(const rational &a){p = a.q * p - a.p * q; q = a.q * q; normalize();return *this;}
  rational &operator*=(const rational &a){p *= a.p; q *= a.q;normalize();return *this;}
  rational &operator/=(const rational &a){p *= a.q; q *= a.p; normalize();return *this;}
  rational &operator-(){p *= -1;return *this;}
  friend rational operator+(const rational &a, const rational &b){return rational(a) += b;}
  friend rational operator*(const rational &a, const rational &b){return rational(a) *= b;}
  friend rational operator-(const rational &a, const rational &b){return rational(a)-=b;}
  friend rational operator/(const rational &a, const rational &b){return rational(a) /= b;}
  friend bool operator<(const rational &a, const rational &b){ // avoid overflow 
    return (long double) a.p * b.q < (long double) a.q * b.p;
  }
  friend bool operator<=(const rational &a, const rational &b){return !(b < a);}
  friend bool operator>(const rational &a, const rational &b){return b < a;}
  friend bool operator>=(const rational &a, const rational &b){return !(a < b);}
  friend bool operator==(const rational &a, const rational &b){return !(a < b) && !(b < a);}
  friend bool operator!=(const rational &a, const rational &b){return (a < b) || (b < a);}
  friend ostream& operator<<(ostream &os, const rational &x){ printf("%.16f",(double)x.p/(double)x.q); return os; }
  friend istream& operator>>(istream &is, rational &x){is>>x.p>>x.q; x.normalize(); return is;}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}


void solve(){
    ll n;cin>>n;
    Divisor d(n);
    if(n==1){
        cout<<1<<endl;
        return ;
    }
    ll ans=0;
    rep(i,1,d.size()){
        ans=gcd(ans,d[i]);
    }
    cout<<ans<<endl;
}