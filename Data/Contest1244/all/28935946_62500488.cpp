#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <typeinfo>
#include <utility>

using namespace std;

#define ll long long

pair<int, ll> c1[100005], c2[100005], c3[100005];
int order1[100005];
int colors[100005];
int n;

vector<vector<int> >tree;

ll dfs(int v, int order = 0, int parent = -1) {
  c1[v].first = order;
  c2[v].first = order;
  c3[v].first = order;
  order1[order] = v;

  for (int i : tree[v]) {
    if (i != parent) {
      dfs(i, order + 1, v);
    }
  }
}


ll get_answer() {
  ll answer = 0;
  for (int i = 0; i < n; i++) {
    if (i >= 2) {
      colors[i] = 6 - colors[i - 1] - colors[i - 2];
    }
    if (colors[i] == 1) {
      answer+=c1[i].second;
    } else if (colors[i] == 2) {
      answer+=c2[i].second;
    } else {
      answer+=c3[i].second;
    }
  }
  return answer;
}

int main() {
  cin >> n;
  tree.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> c1[i].second;
  }

  for (int i = 0; i < n; i++) {
    cin >> c2[i].second;
  }

  for (int i = 0; i < n; i++) {
    cin >> c3[i].second;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (tree[u].size() == 2 || tree[v].size() == 2) {
      cout << "-1";
      return 0;
    }
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  int start;
  for (int i = 0; i < tree.size(); i++) {
    if (tree[i].size() == 1) {
      start = i;
    }
  }

  dfs(start);

  sort(c1, c1 + n);
  sort(c2, c2 + n);
  sort(c3, c3 + n);

  colors[0] = 1;
  colors[1] = 2;

  ll answer = INT64_MAX;
  vector<int>ans;

  ll cur_ans = get_answer();
  if (cur_ans < answer) {
    ans = vector<int>(colors, colors + n);
    answer = cur_ans;
  }

  colors[0] = 1;
  colors[1] = 3;
  cur_ans = get_answer();
  if (cur_ans < answer) {
    ans = vector<int>(colors, colors + n);
    answer = cur_ans;
  }

  colors[0] = 2;
  colors[1] = 1;
  cur_ans = get_answer();
  if (cur_ans < answer) {
    ans = vector<int>(colors, colors + n);
    answer = cur_ans;
  }

  colors[0] = 2;
  colors[1] = 3;
  cur_ans = get_answer();
  if (cur_ans < answer) {
    ans = vector<int>(colors, colors + n);
    answer = cur_ans;
  }

  colors[0] = 3;
  colors[1] = 1;
  cur_ans = get_answer();
  if (cur_ans < answer) {
    ans = vector<int>(colors, colors + n);
    answer = cur_ans;
  }

  colors[0] = 3;
  colors[1] = 2;
  cur_ans = get_answer();
  if (cur_ans < answer) {
    ans = vector<int>(colors, colors + n);
    answer = cur_ans;
  }

  cout << answer << "\n";

  vector<int>final_colors(n);
  for (int i = 0; i < n; i++) {
    final_colors[order1[i]] = ans[i];
  }

  //reverse(final_colors.begin(), final_colors.end());
  for (int i : final_colors) {
    cout << i << " ";
  }
  return 0;
}