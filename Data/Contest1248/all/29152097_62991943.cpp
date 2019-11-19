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
  const int N = 1e5+2;
  LL cl[N][2][2];
  for(int i=0;i<N;i++){
    for(int j=0;j<2;j++) for(int k=0;k<2;k++){
      if(i==0){
        cl[i][k][j] = 1;
      }else if(i==1){
        cl[i][k][j] = 1;
      }else{
        if(k==1){
          cl[i][k][j] = cl[i-1][0][!j];
        }else{
          cl[i][k][j] = cl[i-1][0][!j] + cl[i-1][1][j];
        }
        cl[i][k][j] %= MOD;
      }
    }
  }
  int n,m;cin >> n >> m;
  if(n==1){
    cout << (cl[m][0][0] + cl[m][0][1])%MOD << endl;
  }else if(m==1){
    cout << (cl[n][0][0] + cl[n][0][1])%MOD << endl;
  }else
  cout << ((cl[n][0][0] + cl[n][0][1])%MOD+(cl[m][0][0] + cl[m][0][1])%MOD - 2 + MOD)%MOD << endl;
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}