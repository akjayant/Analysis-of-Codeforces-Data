#pragma GCC optimize ("unroll-loops", "no-stack-protector", "O3")
#include <bits/stdc++.h>
#define F first
#define S second
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
typedef long long ll;

using namespace std;

const int N = (int)1e5 + 5;

int fa[N], vis[N], cc[N], n, m, d = 0, cnt = 0;
vector<int> G[N], group[N];
vector<pair<int, int> > E;

inline int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}
inline void bfs(int s) {
  static queue<int> q;
  q.push(s); fa[s] = find(s + 1);
  group[cnt].push_back(s);
  cc[s] = cnt;
  while(!q.empty()) {
    int x = q.front(); q.pop();
    for(auto v : G[x]) vis[v] = x;
    for(int i = find(1) ; i <= n ; i = find(i + 1)) {
      if(vis[i] != x) fa[i] = find(i + 1), q.push(i), group[cnt].push_back(i), cc[i] = cnt;
    }
  }
  ++cnt;
}
string s[N];
inline void upd(int i, char c, int id) {
  for(auto j : group[i]) s[id][j - 1] = c;
};
inline void get2(int x, int id) {
  d = max(id, d);
  if(x == 1 || x == 2) return;
  get2(x / 2, id + 1);
  get2(x - x / 2, id + 1);
}
inline void get(int j, int x, int id) {
  if(x == 1) {
    /*
    upd(j, '0', id);
    for(int i = id + 1 ; i < d ; ++i) upd(j, '0', i);
    */
  }
  else if(x == 2) {
    //upd(j, '0', id);
    upd(j + 1, '1', id);
    //for(int i = id + 1 ; i < d ; ++i) upd(j, '0', i), upd(j + 1, '0', i);
  }
  else {
    int xx = x / 2;
    //for(int i = 0 ; i < xx ; ++i) upd(j + i, '0', id);
    for(int i = xx ; i < x ; ++i) upd(j + i, '1', id);
    get(j, xx, id + 1);
    get(j + xx, x - xx, id + 1);
  }
}

void init() {
  cin >> n >> m;
  for(int i = 0 ; i < m ; ++i) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    E.emplace_back(a, b);
  }
  for(int i = 1 ; i <= n + 1 ; ++i) fa[i] = i;
}
void solve() {
  for(int i = 1 ; i <= n ; i = find(i + 1)) bfs(i);

  get2(cnt, 0);
  d++;
    for(int i = 0 ; i < n ; ++i) s[0].push_back('0');
    for(int i = 1 ; i < d ; ++i) s[i] = s[0];
    get(0, cnt, 0);
    cout<<cnt-1<<"\n";
}

const int mn=1e6+100;
int e[mn+100],p[mn+100],np,x[mn],y[mn],k,res=1;

void nto()
{
    forinc(i,1,mn) e[i]=i;
    forinc(i,2,mn) if(e[i]==i)
    {
        for(int j=2*i;j<=mn;j+=i) e[j]=i;
    }
    np=0;
    forinc(i,2,mn) if(e[i]==i) p[++np]=i;
}

void phantich(int n)
{
    k=0;
    int i=1;
    int a;
    while(n>1000000)
    {
        while(p[i]<=n/p[i]&&n%p[i]!=0) i++;
        if(p[i]>n/p[i]) a=n;
        else a=p[i];
        x[++k]=a;y[k]=0;
        while(n%a==0) ++y[k],n/=a;
    }
    while(n>1)
    {
        a=e[n];
        x[++k]=a;
        y[k]=0;
        while(n%a==0) ++y[k],n/=a;
    }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  init();
  solve();
}

