#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<int mod> class modint
{   
private:
  int val;
public:
  int value(){ return val; }
  modint(int x=0){ val=x%mod; }
  modint pow(int n){
    modint res(1),x(val);
    while(n>0){ if(n&1) res*=x; x*=x; n>>=1; }
    return res;
  }
  modint inv(){ return pow(mod-2); }
  modint& operator+=(modint rhs){ val+=rhs.val; if(val>=mod) val-=mod; return *this; }
  modint& operator-=(modint rhs){ val+=mod-rhs.val; if(val>=mod) val-=mod; return *this; }
  modint& operator*=(modint rhs){ val=val*rhs.val%mod; return *this; }
  modint& operator/=(modint rhs){ *this*=rhs.inv(); return *this; }
  modint operator+(modint rhs){ return modint(val)+=rhs; }
  modint operator-(modint rhs){ return modint(val)-=rhs; }
  modint operator*(modint rhs){ return modint(val)*=rhs; }
  modint operator/(modint rhs){ return modint(val)/=rhs; }
};

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  using mint=modint<1000000007>;
  int N,M; cin>>N>>M;
  mint ans=mint(2).pow(M)-1;
  ans=ans.pow(N);
  cout<<ans.value()<<endl;
}