#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;
vector<pair<int, int>> arr1;
vector<tuple<long long, int, int>> arr2;
int n;
pair<int, int> coor[N];
int C[N], K[N], dsu[N], sz[N];
bool cool[N];

int get(int v) {
  if (dsu[v] == v) {
    return v;
  }
  return dsu[v] = get(dsu[v]);
}

void merge(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) {
    return;
  }
  if (sz[a] < sz[b]) {
    swap(a, b);
  }
  sz[a] += sz[a] == sz[b];
  cool[a] |= cool[b];
  dsu[b] = a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  iota(dsu, dsu + N, 0);
  fill(sz, sz + N, 1);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> coor[i].first >> coor[i].second;
  }
  for (int i = 0; i < n; ++i) {
    cin >> C[i];
    arr1.emplace_back(C[i], i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> K[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      arr2.emplace_back(1ll * (abs(coor[i].first - coor[j].first) + abs(coor[i].second - coor[j].second)) * (K[i] + K[j]), i, j);
    }
  }
  sort(arr1.begin(), arr1.end(), greater<pair<int, int>>());
  sort(arr2.begin(), arr2.end(), greater<tuple<long long, int, int>>());
  long long RES = 0;
  vector<int> res1;
  vector<pair<int, int>> res2;
  while (!arr1.empty() || !arr2.empty()) {
    long long a = LLONG_MAX, c = LLONG_MAX;
    int b, d, e;
    if (!arr1.empty()) {
      tie(a, b) = arr1.back();
    }
    if (!arr2.empty()) {
      tie(c, d, e) = arr2.back();
    }
    if (a < c) {
      arr1.pop_back();
      if (cool[get(b)]) {
        continue;
      }
      RES += a;
      cool[get(b)] = 1;
      res1.emplace_back(b);
      continue;
    }
    arr2.pop_back();
    if (get(d) == get(e)) {
      continue;
    }
    if (cool[get(d)] && cool[get(e)]) {
      continue;
    }
    merge(d, e);
    RES += c;
    res2.emplace_back(d, e);
  }
  cout << RES << "\n" << res1.size() << "\n";
  for (auto i : res1) {
    cout << i + 1 << " ";
  }
  cout << "\n" << res2.size() << "\n";
  for (auto i : res2) {
    cout << i.first + 1 << " " << i.second + 1 << "\n";
  }

  return 0;
}
