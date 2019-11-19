#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cfloat>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

template<typename CostType>
/// \brief 辺の情報
struct Edge{
  int      to;
  CostType cost;

  Edge(int t, CostType c): to(t), cost(c){
  }
};

template<typename CostType>
class Graph{

private:

  /// \brief adjacent_list_[n]=ノードnの隣接リストを表すvector<Edge>
  std::vector<std::vector<Edge<CostType>>> adjacent_list_;

public:

  /// \brief 頂点数
  const int NODE_SIZE_;

  /// \brief コンストラクタ
  /// \param node_size 頂点数
  explicit Graph(const int node_size): NODE_SIZE_(node_size),
                                       adjacent_list_(node_size){
  }

  /// \brief 有向グラフの辺を生やす
  /// \param from 辺の根本の頂点の番号
  /// \param to 辺の先の頂点の番号
  /// \param cost 辺のコスト
  void SetDirectedEdge(const int from, const int to, const CostType cost){
    adjacent_list_[from].push_back(Edge<CostType>(to, cost));
  }

  /// \brief 無向グラフの辺を生やす
  /// \param node_a 一方の頂点の番号
  /// \param node_b もう一方の頂点の番号
  /// \param cost 辺のコスト
  void
  SetUndirectedEdge(const int node_a, const int node_b, const CostType cost){
    SetDirectedEdge(node_a, node_b, cost);
    SetDirectedEdge(node_b, node_a, cost);
  }

  /// \brief ある頂点の隣接リストを取得
  /// \param node_num 頂点の番号
  /// \return 隣接リスト
  std::vector<Edge<CostType>> GetAdjacentList(int node_num) const{
    return adjacent_list_[node_num];
  }
};

int main(void){
  cout << std::fixed << std::setprecision(16);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  cin>>n;
  std::vector<int64_t> red(n),green(n),blue(n);
  for(int i=0;i<n;i++){
    cin>>red[i];
  }
  for(int i=0;i<n;i++){
    cin>>green[i];
  }
  for(int i=0;i<n;i++){
    cin>>blue[i];
  }

  Graph<int64_t> graph(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    graph.SetUndirectedEdge(a-1,b-1,1);
  }

  int leftnode=-1,rightnode=-1;
  for(int i=0;i<n;i++){
    int size=graph.GetAdjacentList(i).size();
    if(size>=3){
      cout<<-1<<endl;
      return 0;
    }else if(size==1){
      if(leftnode==-1){
        leftnode=i;
      }else{
        rightnode=i;
      }
    }
  }

  int64_t result_cost=INT64_MAX;
  std::vector<int> result_vec;
  for(int sign=-1;sign<=1;sign+=2){
    for(int left_col=1;left_col<=3;left_col++){
      int64_t cost=0;
      std::vector<int> painting(n);
      int color=left_col;
      int prev_node=-1;
      int curr_node=leftnode;
      for(int count=0;count<n;count++){
        painting[curr_node]=color;
        if(color==1){
          cost+=red[curr_node];
        }else if(color==2){
          cost+=green[curr_node];
        }else{
          cost+=blue[curr_node];
        }

        if(count!=n-1){
          std::vector<Edge<int64_t>> list=graph.GetAdjacentList(curr_node);
          if(list.front().to!=prev_node){
            prev_node=curr_node;
            curr_node=list.front().to;
          }else{
            prev_node=curr_node;
            curr_node=list.back().to;
          }
        }
        color+=sign;
        if(color>3) color=1;
        else if(color<=0) color=3;

      }

      if(cost<result_cost){
        result_cost=cost;
        result_vec=painting;
      }
    }
  }

  cout<<result_cost<<endl;
  for(int i=0;i<n-1;i++){
    cout<<result_vec[i]<<" ";
  }
  cout<<result_vec[n-1]<<endl;



  return 0;
}
