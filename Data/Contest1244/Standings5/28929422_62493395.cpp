#include <bits/stdc++.h>

using namespace std;

class customIO {
public:
  istream &in;
  ostream &out;
  customIO(istream &_in, ostream &_out) : in(_in), out(_out) {}
  string next() {
    string s;
    in >> s;
    return s;
  }
  double nextDouble() { return stod(next()); }
  int nextInt() { return stoi(next()); }
  long long nextLong() { return stoll(next()); }
  template <typename T> void print(T t) { out << t; }
  template <typename T, typename... U> void print(T t, U... u) {
    out << t;
    print(u...);
  }
  template <typename T, typename... U> void println(T t, U... u) {
    print(t, u..., "\n");
  }
  void println() { print("\n"); }
};

int n;
vector<vector<int>> tree;
int a[4][100002];
int degree[100002];
int parent[100002];
int colors[100002];
int rescolors[100002];

class CF1244D {
public:
  void solve(customIO &io) {
    n = io.nextInt();
    for (int i = 0; i <= 2; ++i) {
      for (int j = 1; j <= n; ++j) {
        a[i][j] = io.nextInt();
      }
    }
    tree.resize(n + 5);
    int x, y;
    for (int i = 1; i < n; ++i) {
      x = io.nextInt();
      y = io.nextInt();
      tree[x].push_back(y);
      tree[y].push_back(x);
      ++degree[x];
      ++degree[y];
    }
    for (int i = 1; i <= n; ++i) {
      if (degree[i] >= 3) {
        io.println(-1);
        return;
      }
    }
    long long res = 1e18;
    for (int i = 1; i <= n; ++i) {
      if (degree[i] == 2) {
        vector<int> cur;
        cur.push_back(i);
        for (int j : tree[i])
          cur.push_back(j);
        sort(cur.begin(), cur.end());
        do {
          for (int j = 1; j <= 1e5; ++j) {
            parent[j] = -1;
            colors[j] = -1;
          }
          for (int j : cur) {
            parent[j] = i;
          }
          for (int j = 0; j < 3; ++j) {
            colors[cur[j]] = j;
          }
          for (int j : cur) {
            if (j != i) {
              dfs(j, i);
            }
          }
          long long curRes = getSum();
          if (curRes < res) {
            res = curRes;
            saveColors();
          }
        } while (next_permutation(cur.begin(), cur.end()));
        io.println(res);
        for (int i = 1; i <= n; ++i) {
          io.print(rescolors[i], " ");
        }
        io.println();
        return;
      }
    }
    assert(false);
    return;
  }

  void dfs(int cur, int par) {
    int c = colors[cur];
    int cp = colors[par];
    assert(c >= 0 && cp >= 0);
    for (int i : tree[cur]) {
      if (i == par)
        continue;
      for (int j = 0; j < 3; ++j) {
        if (colors[cur] == j || colors[par] == j)
          continue;
        colors[i] = j;
      }
      dfs(i, cur);
    }
  }

  long long getSum() {
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
      res += a[colors[i]][i];
    }
    return res;
  }

  void saveColors() {
    for (int i = 1; i <= n; ++i) {
      rescolors[i] = colors[i] + 1;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout.precision(20);
  istream &in(std::cin);
  ostream &out(std::cout);
  customIO io(in, out);
  CF1244D solver;
  solver.solve(io);
  return 0;
}
