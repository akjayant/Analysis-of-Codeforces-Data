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
int a[255];
long double dp[255],sum;

int32_t main(void) {
  FASTIO;
  n=10;

  for(int i=9;i>=0;--i)
  {
    if(i%2)
    {
      for(int j=10;j>0;j--)
      {
        cin>>k;
        a[i*10+j]=(i+k)*10+j;
        if(k%2)
          a[i*10+j]+=-2*j+11;
      }
    }
    else
    {
      for(int j=1;j<=10;j++)
      {
        cin>>k;
        a[i*10+j]=(i+k)*10+j;
        if(k%2)
          a[i*10+j]+=-2*j+11;
      }
    }
  }

//   for(int i=1;i<=100;++i)
    // debug(i,a[i]);

  sum=0;
  for(int i=1;i<6;++i)
  {
    dp[100-i]+=(sum+6.00)/i;
    sum+=dp[100-i];
    // debug(100-i,dp[100-i]);
  }

  for(int i=94;i>0;i--)
  {
    for(int j=1;j<=6;++j)
      dp[i]+=(1/6.0)*min(dp[i+j],dp[a[i+j]]);
    dp[i]=dp[i]+1;
  }

  cout<<std::fixed<<std::setprecision(10)<<dp[1]<<endl;;
  return 0;
}