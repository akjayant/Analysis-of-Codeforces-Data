#include <bits/stdc++.h>
using namespace std;
const double pi=2*acos(0.0);
double inff=1.0/0.0;
#define ll           long long int
#define inf          1000000000
#define MOD          1000000007
#define pb           push_back
#define sz(x)        (int)x.size()
#define mp           make_pair
#define lbd          lower_bound
#define ubd          upper_bound
#define ipair        pair<ll,ll> 
#define all(v)       v.begin(),v.end()
#define watch(x)     cout<<(#x)<<" is "<<(x)<<endl;
#define rep(a,b,c)   for(a=(int)b;a<(int)c;a++)    
#define bac(a,b,c)   for(a=(int)b;a>=(int)c;a--)
#define se           second
#define f            first
#define ios          ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
#define mem(a,val)   memset(a,val,sizeof a)
#define endl         "\n"
#define mxn          500002
#define vi           vector<ll>
#define vii          vector<ipair> 
#define si           set<ll> 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
/*Variables Start*/
ll x,y,n,i,z,j,k,w,u,q,m,t;
/*Variables End*/
void solve()
{
  ll a,b,c,d,k;
  cin>>a>>b>>c>>d>>k;
  w=(a+c-1)/c;
  y=(b+d-1)/d;
  if(w+y<=k)
  {
    cout<<w<<" "<<y<<endl;
  }
  else cout<<"-1"<<endl;
}
int main() 
{ 
  int TESTS=1;
  ios;
  cin>>TESTS;
  while(TESTS--)
  {
    solve();
  }
}