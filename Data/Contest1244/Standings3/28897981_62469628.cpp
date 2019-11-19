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
  
  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    string s;cin >> s;
    int fs,st;
    fs = st = -1;
    for(int i=1;i<=n;i++){
      if(s[i-1]=='1') st = i;
      if(s[i-1]=='1'&&fs==-1) fs = i;
    }
    if(fs==st){
      if(fs==-1) cout << n << endl;
      else cout << max(n,max(2*st,2*(n-fs+1))) << endl;
    }else{
      cout << max(max(fs,n-st+1)+2*(st-fs)+1,max(n,max(2*st,2*(n-fs+1)))) << endl;
    }
  }
  
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}