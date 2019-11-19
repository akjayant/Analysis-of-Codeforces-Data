#include <iostream>
#include <list>
#include <vector>
#include <limits>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector< vector<int> > prices(n, vector<int>(3,0));
    vector< list<int> > adj(n);
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < n; ++i){
            cin >> prices[i][j];
        }
    }
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
     for(int i = 0; i < n; i++){
        if(adj[i].size() > 2){
            cout << -1 << "\n";
            return 0;
        }
    }
    int first =-1;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 1){
            first = i;
            break;
        }
    }
    int second = adj[first].front();
    long long int min_price = numeric_limits<long long int>::max();
    vector<int> min_vector(n);
    for(int c1 = 0; c1 < 3; c1++){
        for(int c2 = 0; c2 < 3; c2++){
            if(c1 == c2) continue;
            vector<bool> visited(n, false);
            vector<int> cc1(n, -1);
            vector<int> cc2(n, -1);
            cc2[first] = c1;
            cc1[second] = c1;
            cc2[second] = c2;
            int cur1 = first;
            long long int total_price = prices[first][c1];
            visited[first] = true;
            visited[second] = true;
            list<int> bfs_list;
            bfs_list.push_back(second);
            while(!bfs_list.empty()){
                int cc3 = 0;
                int curr = bfs_list.front();
                for(int o = 0; o < 2; o++){
                    if(cc3 == cc1[curr] || cc3 == cc2[curr]) cc3++;
                }
                total_price += prices[curr][cc2[curr]];
                
                for(auto adj_i : adj[bfs_list.front()]){
                    if(!visited[adj_i]){
                        if(!visited[adj_i]){
                            bfs_list.push_back(adj_i);
                            visited[adj_i] = true;
                            cc1[adj_i] = cc2[curr];
                            cc2[adj_i] = cc3;
                        }  
                    }
                }
                visited[curr] = true;
                bfs_list.pop_front();
            }
            
            if(total_price < min_price){
                min_price = total_price;
                min_vector = cc2;
            }
        }
    }
    cout << min_price << "\n";
    for(auto i : min_vector){
        cout << i+1 << " "; 
    }
    cout << "\n";
}