#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <queue>
#include <stack>
#include <stdarg.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

vector<vector<int>> 
getChange() {
  vector<vector<int>> ans;

  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      for (int k=0; k<3; k++) {
        if (i==j || j==k || i==k) continue;
        ans.push_back(vector<int>{i, j, k});
      }

  return ans;
}

int
main() {
  int n;
  cin>>n;

  int cost[100005][3] = {0};
  for (int c = 0; c < 3; c++)
    for (int i=1; i<=n; i++)
      cin>>cost[i][c];

  vector<vector<int>> link(n+1, vector<int>());
  int x, y;
  int start_x = -1, start_y = -1;
  for (int i=0; i<n-1; i++) {
    cin>>x>>y;

    if (start_x == -1) {
      start_x = x;
      start_y = y;
    }

    link[x].push_back(y);
    link[y].push_back(x);
  }

  vector<int> color(n+1, -1);
  vector<int> prev(n+1, -1);

  color[x] = 0;
  prev[x] = 1;
  color[y] = 1;
  prev[y] = 0;

  stack<int> data;
  data.push(x);
  data.push(y);

  while (data.size() > 0) {
    int p = data.top();
    data.pop();

    for (int next : link[p]) {
      if (color[next] != -1) continue;

      prev[next] = color[p];
      color[next] = 3-color[p]-prev[p];
      data.push(next);
    }
  }

  bool valid = true;
  for (int i=1; i<=n; i++) {
    if (color[i] == -1) {
      valid = false;
      break;
    }
    if (link[i].size() > 2) {
      valid = false;
      break;
    }
  }

  if (!valid) {
    cout<<-1<<endl;
    return 0;
  }

  int64_t ans = -1;
  vector<int> out;
  for (auto p : getChange()) {
    int64_t current = 0;
    for (int i=1; i<=n; i++) 
      current += cost[i][p[color[i]]];

    if (ans == -1 || current < ans) {
      ans = current;
      out = p;
    }
  }
  if (ans == -1) {
    cout<<ans<<endl;
  }
  else {
    cout<<ans<<endl;
    for (int i=1; i<=n; i++)
      cout<<out[color[i]] + 1<<" ";
    cout<<endl;
  }

  return 0;
}

