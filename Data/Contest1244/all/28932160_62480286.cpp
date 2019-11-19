#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000 + 5;
const long long INF = 0x7F7F7F7F7F7F7F7F;

struct Graph {
  int cnte;
  int Head[MaxN], To[MaxN * 2], Next[MaxN * 2];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N, Rt;
int Deg[MaxN];
int C[3][MaxN], A[MaxN];
long long F[MaxN][3][3];
int Pre[MaxN][3][3];
int Ans[MaxN];
Graph G;

void init() {
  cin >> N;
  for (int i = 0; i < 3; ++i)
    for (int j = 1; j <= N; ++j)
      scanf("%d", &C[i][j]);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Deg[u]++, Deg[v]++;
    G.addEdge(u, v);
    G.addEdge(v, u);
  }
}

inline bool checkChain() {
  for (int i = 1; i <= N; ++i) {
    if (Deg[i] == 1) Rt = i;
    if (Deg[i] > 2) return false;
  }
  return true;
}

void dfs(int u, int i) {
  A[i] = u;
  for (int e = G.Head[u]; e; e = G.Next[e]) {
    int v = G.To[e];
    if (v == A[i - 1]) continue;
    dfs(v, i + 1);
  }
}

void print(int i, int j, int k) {
  if (i == 2) {
    Ans[A[1]] = j + 1;
    Ans[A[2]] = k + 1;
    return;
  }
  Ans[A[i]] = k + 1;
  print(i - 1, Pre[i][j][k], j);
}

void solve() {
  if (checkChain() == false) {
    puts("-1");
    return;
  }
  dfs(Rt, 1);

  memset(F, 0x7F, sizeof F);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      if (i == j) continue;
      F[2][i][j] = C[i][A[1]] + C[j][A[2]];
    }
  for (int i = 3; i <= N; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j == k) continue;
        for (int x = 0; x < 3; ++x) {
          if (x == j || x == k) continue;
          if (F[i - 1][j][k] + C[x][A[i]] < F[i][k][x]) {
            F[i][k][x] = F[i - 1][j][k] + C[x][A[i]];
            Pre[i][k][x] = j;
          }
          F[i][k][x] = min(F[i][k][x], F[i - 1][j][k] + C[x][A[i]]);
        }
      }
    }
  }
  int ansi = 0, ansj = 0;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      if (F[N][i][j] < F[N][ansi][ansj])
        ansi = i, ansj = j;
  cout << F[N][ansi][ansj] << endl;
  print(N, ansi, ansj);
  for (int i = 1; i <= N; ++i) printf("%d%c", Ans[i], " \n"[i == N]);
}

int main() {
  init();
  solve();
  return 0;
}