#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }
#define ALL(x) (x).begin(), (x).end()
LL POW(LL a,LL p,LL M){ if(!p) return 1LL;LL T = POW(a,p/2,M);T = T*T%M; if(p&1) T=T*(a%M)%M; return T; }
LL SQRT(LL a) { LL b = (LL)sqrtl(((double)a)+0.5); while(b*b<a) ++b; while(b*b>a) --b; return (b*b==a)?b:-1; }
//endl
//<------------------------edits---------------------------------------------->
const LL MOD = 1e9+7;//998244353
// #define LOCAL LDD
// #define int LL

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);cout << fixed;
#ifdef LOCAL
  freopen("input.txt", "rt", stdin);
#endif
  
  LL n,p,w,d;cin >> n >> p >> w >> d;
  LL f = -1;
  for(int i=0;i<w;i++){
    LL tt = i;
    tt *= d;
    tt %= w;
    if(tt==p%w){
      LL h = p-i*d;
      if(h>=0){
        h/=w;
        if(h+i<=n){
          cout << h << " " << i << " " << n-h-i << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}