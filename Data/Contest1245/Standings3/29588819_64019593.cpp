#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <queue>
#include <stdarg.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

#define ll long long

using namespace std;

ll
dist(vector<pair<int, int>> & pos, int a, int b) {
  ll ans = 0;
  ans += abs(pos[a].first - pos[b].first);
  ans += abs(pos[a].second - pos[b].second);
  
  return ans;
}

int
main() {
  int n;
  cin>>n;

  vector<pair<int, int>> pos(n+1);
  for (int i=1; i<=n; i++) cin>>pos[i].first>>pos[i].second;

  vector<int> c(n+1);
  for (int i=1; i<=n; i++) cin>>c[i];

  vector<int> k(n+1);
  for (int i=1; i<=n; i++) cin>>k[i];

  priority_queue<pair<ll, pair<int, int>>, 
    vector<pair<ll, pair<int, int>>>, 
    greater<pair<ll, pair<int, int>>>> data;
  for (int i=1; i<=n; i++)
    data.push({c[i], {i, 0}});

  vector<int> stations;
  vector<pair<int, int>> lines;
  ll ans = 0;
  vector<bool> visited(n+1, false);
  while (data.size() > 0) {
    auto p = data.top();
    data.pop();
    if (visited[p.second.first]) continue;
    visited[p.second.first] = true;

    ans += p.first;
    if (p.second.second == 0) 
      stations.push_back(p.second.first);
    else
      lines.push_back(p.second);

    int index = p.second.first;
    for (int i=1; i<=n; i++) {
      if (i==index) continue;
      if (visited[i]) continue;

      data.push({dist(pos, i, index) * (k[i] + k[index]), {i, index}});
    }
  }

  cout<<ans<<endl;
  cout<<stations.size()<<endl;
  for (auto p : stations)
    cout<<p<<" ";
  cout<<endl;
  cout<<lines.size()<<endl;
  for (auto p : lines) 
    cout<<p.first<<" "<<p.second<<endl;
  return 0;
}

