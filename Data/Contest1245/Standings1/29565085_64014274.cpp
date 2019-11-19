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

int n,m,i,j,mod;
vector<pair<int,int>> a,edg;
vector<int> k,pwr,par;
vector<pair<int,pair<int,int>>> edges;

int findParent(int n)
{
  if(par[n]==n)
    return n;
  return par[n]=findParent(par[n]);
}

int32_t main(void) {
  FASTIO;
  cin>>n;
  a.resize(n+1);
  k.resize(n+1);

  for(int i=0;i<=n;++i)
    par.push_back(i);
  for(int i=1;i<=n;++i)
    cin>>a[i].first>>a[i].second;
  for(int i=1;i<=n;++i)
  {
    int cst;
    cin>>cst;
    edges.push_back({cst,{0,i}});
  }
  for(int i=1;i<=n;++i)
    cin>>k[i];

  for(int i=1;i<=n;++i)
  for(int j=i+1;j<=n;++j)
    edges.push_back({(k[i]+k[j])*(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second)),{i,j}});

  sort(edges.begin(),edges.end());
  debug(edges);
  int ans=0;
  for(auto x:edges)
  {
    if(findParent(x.second.first)==findParent(x.second.second))
      continue;
    if(x.second.first)
      edg.push_back(x.second);
    else
      pwr.push_back(x.second.second);
    par[findParent(x.second.first)]=findParent(x.second.second);
    ans+=x.first;
  }

  cout<<ans<<endl;
  cout<<(int)pwr.size()<<endl;
  for(auto x:pwr)
    cout<<x<<" ";
  cout<<endl;

  cout<<(int)edg.size()<<endl;
  for(auto x:edg)
    cout<<x.first<<" "<<x.second<<endl;

  return 0;
}