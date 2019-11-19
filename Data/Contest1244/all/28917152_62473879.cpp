#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e6;
vector<int> edges[N];
int dist[N];
void dfs(int v)
{
    for(auto i : edges[v])
    {
        if(dist[i] == -1)
            dist[i] = dist[v] + 1, dfs(i);
    }
}
signed main()
{
  int n, p, d, w;
  cin>>n>>p>>w>>d;
  for(int i = 0; i < w; i++)
  {
      dist[i] = -1;
      edges[i].push_back((i + d) % w);
  }
  dist[0] = 0;
  int need = p % w;
  dfs(0);
  if(dist[need] == -1)
  {
      cout<<-1<<endl;
      return 0;
  }
  int cnt = dist[need];
  int gg = cnt * d;

  if(gg > p || cnt > n ||n - ((p - gg) / w) - cnt < 0 )
  {
      cout<<-1<<endl;
      return 0;
  }
  cout<<(p - gg) / w<<" "<<cnt<<" "<<n - ((p - gg) / w) - cnt<<endl;
}