#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);i++)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 +99);
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T mpow(T a, T n) {
   T res = 1;
   for(;n;n>>=1) {
      if (n & 1) res = res * a;
      a = a * a;
   }
   return res;
}

//cin.tie(0);ios::sync_with_stdio(false);

ll dp[100010][2][2]={};

ll sum(ll n){
   return (dp[n][0][0]+dp[n][0][1]+dp[n][1][0]+dp[n][1][1])%mod;
}

signed main(){
   ll m,n;cin>>n>>m;
   
   rep(j,0,2)rep(k,0,2){
         dp[2][j][k]=1;
   }
   rep(i,3,100010){
      dp[i][0][0]=dp[i-1][1][0];
      dp[i][0][1]=dp[i-1][0][0]+dp[i-1][1][0];
      dp[i][1][0]=dp[i-1][0][1]+dp[i-1][1][1];
      dp[i][1][1]=dp[i-1][0][1];
      rep(j,0,2)rep(k,0,2){
         dp[i][j][k]%=mod;
      }
   }

   if(n==1 && m==1)cout<<2<<endl;
   else if(n==1)cout<<sum(m)<<endl;
   else if(m==1)cout<<sum(n)<<endl;
   else cout<<(sum(n)+sum(m)+mod-2)%mod<<endl;

}