#include <sstream>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<ctime>
#include<cmath>
#include<map>
#include<limits.h>
#include<stack>
#include<random>
#include<queue>
#include<list>
#include<math.h>
#include<complex>
using namespace std;
#define ll long long int
#define ld long double
#define key pair<ld,ld>
#define ii pair<int,int>
#define si set<int>
#define vii vector<pair<int,int> >
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int> >
#define vs vector<string>
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nu 100001
#define mul(x,y) ((ll)(x)*(y))%mod
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forn(i, n) for (int i = 0; i < int(n); i++)
const ll INF = 9223372036854775807;
const ll NINF=-100000000000000000;
const ll mod = 1000000007;
ll power(ll x,ll y)
{
  if (y == 0)
    return 1;
  ll p = power(x, y/2) % mod;
  p = (p * p) % mod;
  
  return (y%2 == 0)? p : (x * p) % mod;
}
ll divide(ll a,ll b)
{
  if (a%b==0)
    {
      return a/b;
    }
  else
    return a/b +1;
}
ll gcd(ll a,ll b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}
int main()
{
  int n,m;
  cin>>n>>m;
  vll dp(100001);
  dp[1]=2;
  dp[2]=4;
  for(int i=3;i<100001;i++)
    {
      dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
  cout<<(((dp[m]+dp[n])%mod)-2+mod)%mod<<endl;
}
