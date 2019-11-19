#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<long long, pair<int, int> > > edges;
const int N = 2020;
int x[N], y[N], c[N], k[N], rep[N], len[N];

long long cost(int i, int j) {
  return (k[i] + k[j]) * (long long) (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}

int fs(int node) {
  if (rep[node] == node) return node;
  rep[node] = fs(rep[node]);
  return rep[node];
}

void joini(int u, int v) {
  if (len[u] > len[v]) {
    rep[v] = u;
  } else {
    rep[u] = v;
    if (len[u] == len[v]) {
      len[v]++;
    }
  }
}

int main() {

  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &k[i]);
  }

  for (int i = 0; i < n; i++) {
    edges.push_back(make_pair(c[i], make_pair(i, n)));
    for (int j = i + 1; j < n; j++) {
      edges.push_back(make_pair(cost(i, j), make_pair(i, j)));
    }
  }
  for (int i = 0; i <= n; i++) {
    rep[i] = i;
    len[i] = 1;
  }
  sort(edges.begin(), edges.end());
  int v = 0, e = 0;
  vector<pair<int, int> > connections;
  vector<int> cities;
  long long yen = 0;
  for (vector<pair<long long, pair<int, int> > >::iterator it = edges.begin(); it != edges.end(); it++) {
    pair<int, int> edge = it->second;
    if (fs(edge.first) != fs(edge.second)) {
      joini(fs(edge.first), fs(edge.second));
      yen += it->first;
      if (edge.second == n) {
        v++;
        cities.push_back(edge.first);
      } else {
        e++;
        connections.push_back(edge);
      }
    }
  }
  cout << yen << endl;
  printf("%d\n", v);
  for (vector<int>::iterator it = cities.begin(); it != cities.end(); it++) {
    if (it != cities.begin()) printf(" ");
    printf("%d", *it + 1);
  }
  printf("\n%d\n", e);
  for (vector<pair<int, int> >::iterator it = connections.begin(); it != connections.end(); it++) {
    printf("%d %d\n", it->first + 1, it->second + 1);
  }

  return 0;
}
