#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct UnionFind{
private:
  vector<int> data;
public:
  int N;
  UnionFind(int n) : data(n, -1), N(n){}
  bool unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    --N;
    if(data[y] < data[x]) swap(x,y);
    data[x] += data[y];
    data[y] = x;
    return x != y;
  }
  bool same(int x, int y){ return find(x) == find(y); }
  int find(int x){
    if(data[x] < 0) return x;
    return data[x] = find(data[x]);
  }
  int size(int x){ return -data[find(x)]; }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> X(n), Y(n);
  for(int i = 0; i < n; ++i){
    cin >> X[i] >> Y[i];
  }
  vector<int> C(n), K(n);
  for(int i = 0; i < n; ++i) cin >> C[i];
  for(int i = 0; i < n; ++i) cin >> K[i];
  vector<tuple<long long, int, int>> T;
  vector<int> V;
  vector<pair<int,int>> E;
  for(int i = 0; i < n; ++i){
    T.emplace_back(C[i],i,n);
  }
  for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
      long long c = ((long long)(abs(X[i]-X[j])+abs(Y[i]-Y[j])))*(K[i]+K[j]);
      T.emplace_back(c,i,j);
    }
  }
  sort(T.begin(), T.end());
  UnionFind uf(n+1);
  long long ans = 0;
  for(auto e : T){
    long long c;
    int a, b;
    tie(c,a,b) = e;
    if(uf.same(a,b)) continue;
    uf.unite(a,b);
    ans += c;
    if(b == n) V.push_back(a);
    else E.emplace_back(a,b);
  }
  cout << ans<< endl;
  cout << V.size() << endl;
  for(auto v : V) cout << v+1 << " ";
  cout << endl;
  cout << E.size() << endl;
  for(auto e : E)
    cout << e.first+1 << " " << e.second+1 << endl;
}
