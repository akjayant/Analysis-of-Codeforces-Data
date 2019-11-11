#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const ll MOD = 1e9+7;

ll p[100009], b[100009];
void pre(){

  p[1]=1, p[2]=1, b[1]=1, b[2]=3;
  repA(i,3,100008)b[i]=((3*b[i-1])%MOD-b[i-2]+2*MOD)%MOD;
  repA(i,3,100008)p[i]=((3*p[i-1])%MOD-p[i-2]+2*MOD)%MOD;
}


void solve(){

}

ll update(ll ans, ll m){
  if(m%2)ans=(ans*b[(m+1)/2])%MOD;
  else ans=(ans*p[m/2+2])%MOD;
  return ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();

  // rep(i,500)cout<<p[i]<< ' ';cout<<endl;



  string s;cin>>s;
  int w=0, m=0;
  ll ans=1;
  repA(i, 0, sz(s)-1){
    if(s[i]=='m'||s[i]=='w'){cout<<0<<endl;return 0;}
    if(s[i]=='u'){
      w++;
      if(m>0) ans=update(ans, m);
      m=0;
    }
    else if(s[i]=='n'){
      m++;
      if(w>0) ans=update(ans, w);
      w=0;
    }
    else if(m>0){
      ans=update(ans, m);
      m=0;
    }
    else if(w>0){
      ans=update(ans, w);
      w=0;
    }
  }
  if(w>0)ans=update(ans, w);
  if(m>0)ans=update(ans, m);
  cout << ans;



	return 0;
}
