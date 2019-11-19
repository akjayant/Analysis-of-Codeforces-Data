#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define endl "\n"
#define int long long int
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string to_string(string s)      {    return '"' + s + '"';   }
string to_string(const char* s) {   return to_string((string) s);   }
string to_string(bool b)        {   return (b ? "true" : "false");  }

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int n,m,k,i,j,mod;
vector<int> a;
int dp[40][2][2];
string s,t;

string toBin(int n)
{
  string s;
  for(int i=35;i>=0;--i)
  {
    if(n&(1LL<<i))
      s+="1";
    else
      s+="0";
  }
  return s;
}

int solve(int pos,bool f,bool g)
{
  if(pos==36)
    return 1;
  int &ans=dp[pos][f][g];
  if(ans!=-1)
    return ans;
  ans=0;

  int lm=s[pos]-'0',rm=t[pos]-'0';

  if(!f)
    lm=1;
  if(!g)
    rm=1;

  for(int i=0;i<=lm;++i)
  for(int j=0;j<=rm;++j)
  {
    if(i==1&&j==1)
      continue;
    ans+=solve(pos+1,f&&(i==lm),g&&(j==rm));
  }

  return ans;
}

int find(int l,int r)
{
  if(l<0||r<0)
    return 0;

  memset(dp,-1,sizeof(dp));
  s=toBin(l);
  t=toBin(r);
  int ans=solve(0,true,true);
  debug(ans,l,r);
  return ans;
}

int32_t main(void) {
  FASTIO;
  int tc;
  cin>>tc;
  for(int i=0;i<tc;++i)
  {
    int n,m;
    cin>>n>>m;
    int ans=0;
    ans+=find(n-1,n-1);
    ans-=2*find(n-1,m);
    ans+=find(m,m);
    cout<<ans<<endl;
  }
  return 0;
}