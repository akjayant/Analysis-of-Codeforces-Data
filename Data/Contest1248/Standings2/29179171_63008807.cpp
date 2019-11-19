#include <bits/stdc++.h>

#define FOR(i, a, b) for(long i = (long)a;i < (long)b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(long i = (long)b-1;i >= (long)a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#ifdef ENABLE_DEBUG
#define dump(x) cerr<<#x"="<<x<<endl;
#define dumparr(x,n) cerr<<#x"["<<n<<"]="<<x[n]<<endl;
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)
#else
#define dump(x)
#define dumparr(x,n)
#define DEBUG_PRINT(...) 
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
void print_pair(pll a){
  cerr<<"("<<a.first<<", "<<a.second<<") ";
}
template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}
std::vector<std::vector<int>> graph;
std::vector<bool> used;
std::vector<int> order;
std::vector<int> group;
std::vector<std::vector<int>> rev_graph(graph.size());
void dfs(int i){
    if(used[i]==true){
        return;
    }
    used[i]=true;
    for (auto &&to : graph[i])
    {
        dfs(to);
    }
    order.push_back(i);
}
void rdfs(int idx,int g){
    if(group[idx]!=-1)return;
    group[idx]=g;
    for (auto &&to : rev_graph[idx])
    {
        rdfs(to,g);
    }
    
}
std::vector<std::vector<int>> strongly_connected(){
    order.clear();
    std::vector<std::vector<int>> t;
    t.clear();
    used.clear();
    used.resize(graph.size());
    fill(used.begin(),used.end(),false);
    group.clear();
    group.resize(graph.size());
    rev_graph.clear();
    rev_graph.resize(graph.size());
    for(int i=0;i<graph.size();i++){
        if(used[i]==false){
            dfs(i);
        }
    }
    for (int i=0;i<graph.size();i++)
    {
        for (auto &&j : graph[i])
        {
            rev_graph[j].push_back(i);
        }
    }
    std::fill(group.begin(),group.end(),-1);
    int g=0;
    reverse(order.begin(),order.end());
    for (auto &&i : order)
    {
        if(group[i]!=-1)continue;
        rdfs(i,g++);
    }
    t.resize(g);
    for(long long i = 0; i < group.size(); i++){
        t[group[i]].push_back(i);        
    }
    return (t);
}
int main(){
  ll t;
  scanf("%lld",&t);
  For(times,t){
    ll n,m;
    graph.clear();
    scanf("%lld%lld",&n,&m);
    graph.resize(n);
    REP(m){
      ll a,b;
      scanf("%lld%lld",&a,&b);
      if(a!=b){
        graph[a-1].push_back(b-1);
      }
    }
    vector<vector<int>> t = strongly_connected();
    if(t.size()==1){
      cout<<"No"<<endl;
      continue;
    }else{
      cout<<"Yes"<<endl;
      cout<<n-t[0].size()<<" "<<t[0].size()<<endl;
      REP(t.size()-1){
        For(j,t[i+1].size())
          printf("%d ",t[i+1][j]+1);
        printf("\n");
      }
      REP(t[0].size()){
        printf("%d ",t[0][i]+1);
      }
      printf("\n");
    }
  }
  return 0;
}

