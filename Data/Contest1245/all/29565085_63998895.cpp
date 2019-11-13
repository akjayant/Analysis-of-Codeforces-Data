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
vector<int> a,fib;

int32_t main(void) {
  FASTIO;
  mod=1000000007;
  string s;
  cin>>s;
  int ans=1;
  int i=0,n=s.size();

  fib={1,1};
  while(i<=n)
  {
    fib.push_back((fib[i]+fib[i+1])%mod);
    i++;
  }

  i=0;
  while(i<n)
  {
    if(s[i]=='m'||s[i]=='w')
    {
      ans=0;
      i++;
      continue;
    }

    if(s[i]!='n'&&s[i]!='u')
    {
      i++;
      continue;
    }
    j=i;
    while(j<n&&s[j]==s[i])
      j++;
    ans=(ans*fib[j-i])%mod;
    i=j;
  }

  cout<<ans<<endl;

  return 0;
}