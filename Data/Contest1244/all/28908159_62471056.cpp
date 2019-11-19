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
  cin>>n;
  string str;
  cin>>str;
  w=0;
  rep(i,0,sz(str))
  {
    if(str[i]=='1')
    {
      w=max({w,n,2*(i+1),2*(n-i)});
    }
    w=max(w,i+1);
  }
  cout<<w<<endl;
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