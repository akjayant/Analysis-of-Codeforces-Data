#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i < int(n); i++)
#define LL long long

// 素集合データ構造
struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
    rep(i,n) par[i] = i;
  }

  // データxが属する木の根を得る
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // データの根ノードを得る
    x = find(x);
    y = find(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    // sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool same(int x, int y) {
    return find(x) == find(y);
  }

  // データxが含まれる木の大きさを返す
  int size(int x) {
    return sizes[find(x)];
  }
};

// 頂点a, bをつなぐコストcostの（無向）辺
struct Edge
{
  LL a, b, cost;

  // コストの大小で順序定義
  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

// 頂点数と辺集合の組として定義したグラフ
struct Graph
{

  int n;  // 頂点数
  vector<Edge> es;  // 辺集合

  // クラスカル法で無向最小全域木のコストの和を計算する
  // グラフが非連結のときは最小全域森のコストの和となる
  int kruskal() {
    // コストが小さい順にソート
    sort(es.begin(), es.end());

    UnionFind uf(n);
    LL min_cost = 0;

    vector<int> ans1;
    vector<pair<int,int>> ans2;

    rep(ei, es.size()) {
      Edge& e = es[ei];
      if (!uf.same(e.a, e.b)) {
        // 辺を追加しても閉路ができないなら、その辺を採用する
        min_cost += e.cost;
        uf.unite(e.a, e.b);
        if (e.b == n-1){
          ans1.push_back(e.a+1);
        }else{
          ans2.push_back(make_pair(e.a+1,e.b+1));
        }
      }
    }

    cout << min_cost << endl;

    cout << ans1.size() << endl;
    for ( int i = 0; i < ans1.size(); i++ ){
      cout << ans1[i] << ( i + 1 < ans1.size() ? ' ' : '\n' );
    }

    cout << ans2.size() << endl;
    for ( int i = 0; i < ans2.size(); i++ ){
      cout << ans2[i].first << ' ' << ans2[i].second << "\n";
    }

  }
};

// 標準入力からグラフを読み込む
Graph input_graph() {
  Graph g;
  int N;
  cin >> N;

  LL XYs[2003][2];
  for (size_t i = 0; i < N; i++) {
    cin >> XYs[i][0] >> XYs[i][1];
  }

  LL cc[2003];
  for (size_t i = 0; i < N; i++) {
    cin >> cc[i];
  }

  LL kk[2003];
  for (size_t i = 0; i < N; i++) {
    cin >> kk[i];
  }

  g.n = N + 1;

  for (size_t i = 0; i < N; i++) {
    Edge e;
    e.a = i;
    e.b = N;
    e.cost = cc[i];
    g.es.push_back(e);
  }

  for (size_t i = 0; i < N; i++) {
    LL xi = XYs[i][0];
    LL yi = XYs[i][1];
    for (size_t j = i+1; j < N; j++) {
      Edge e;
      LL xj = XYs[j][0];
      LL yj = XYs[j][1];
      LL k = kk[i] + kk[j];
      e.a = i;
      e.b = j;
      e.cost = k * (abs(xi-xj) + abs(yi-yj));
      g.es.push_back(e);
    }
  }

  return g;
}


int main()
{
  Graph g = input_graph();
  g.kruskal();
  return 0;
}
