#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
using namespace std;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

template<typename ...Ts>
void show(Ts... ts){
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}

ll cnt(ll x){
    vector<int> dp(x+1,0);
    dp[0]=1;dp[1]=1;
    REP(i,1,x){
        dp[i+1]=dp[i]+dp[i-1];
        dp[i+1]%=mod;
    }
    return dp[x];
}

int main(void){
    ll n,m,ans=0;
    cin>>n>>m;
    /*
    vector<int> a;
    rep(i,n){
        cin>>x;
        a.push_back(x);
    }

    sort(all(a),greater<int>());
    sort(all(a));
    */
    ans=(2*(cnt(n)+cnt(m))-2)%mod;
    cout<<ans<<endl;

}

