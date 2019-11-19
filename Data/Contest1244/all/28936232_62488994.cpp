#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;

const int N = 1e5 + 10 ;
const ll inf = 1e18 ;
vector < int > G[N];
ll cost[N][3];
vector < int > ve;
void dfs(int u, int p){
     ve.push_back(u);
     for(auto v : G[u]){
          if(v == p) continue ;
          dfs(v , u);
     }
}

ll memo[N][4][4];

ll solve(int i , int last , int last2){

   if(i == ve.size()) return 0 ;

   ll &ret = memo[i][last][last2];
   if(ret != -1) return ret ;

   ret = inf ;

   for(int j = 0 ; j < 3;  j++)
       if(j != last && j != last2)
           ret = min(ret , cost[ve[i]][j] + solve(i + 1 , j , last));

   return ret ;
}

int res[N];
void build(int i, int last , int last2){

     if(i == ve.size()) return ;

     ll optimal = solve(i , last , last2);

     for(int j = 0 ; j < 3 ; j++){
            if(j != last && j != last2){
                  ll c = cost[ve[i]][j] + solve(i + 1 , j , last);
                  if(c == optimal){
                       res[ve[i]] = j + 1;
                       build(i + 1 , j , last);
                       break ;
                  }
            }
     }
}

int main()
{
    ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

    int n ; cin >> n;

    for(int i = 0 ; i < 3 ; i++){
          for(int j = 1 ; j <= n ; j++){
               cin >> cost[j][i] ;
          }
    }

    for(int i = 0 ; i < n - 1 ; i++){
          int u , v ;
          cin >> u >> v ;
          G[u].push_back(v);
          G[v].push_back(u);
    }

    int root = 0 ;

    for(int i = 1 ; i <= n ; i++){
         if(G[i].size() >= 3) return cout << -1 << endl , 0;
         if(G[i].size() == 1) root = i ;
    }

    memset(memo , -1 , sizeof memo);

    dfs(root , -1);

    cout << solve(0, 3, 3) << endl ;


    build(0, 3, 3);

    for(int i = 1 ; i <= n ; i++)
        cout << res[i] << " " ;


    return 0;
}
