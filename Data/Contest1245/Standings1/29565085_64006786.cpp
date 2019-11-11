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

int32_t main(void) {
  FASTIO;
  int tc;
  cin>>tc;
  for(int i=0;i<tc;++i)
  {
    string s,t;
    int a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    cin>>s;

    int cnt=n;
    t="";
    for(int i=0;i<n;++i)
    {
      if(s[i]=='S'&&a)
      {
        t+="R";
        a--;
      }
      else if(s[i]=='P'&&c)
      {
        t+="S";
        c--;
      }
      else if(s[i]=='R'&&b)
      {
        t+="P";
        b--;
      }
      else
      {
        t+=".";
        cnt--;
      }
    }

    if(cnt<(n+1)/2)
    {
      cout<<"NO"<<endl;
      continue;
    }

    for(auto &x:t)
    {
      if(x!='.')
        continue;
      if(a)
      {
        x='R';
        a--;
      }
      else if(c)
      {
        x='S';
        c--;
      }
      else if(b)
      {
        x='P';
        b--;
      }
    }

    cout<<"YES"<<endl;
    cout<<t<<endl;
  }
  return 0;
}