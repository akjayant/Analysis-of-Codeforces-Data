#include <bits/stdc++.h>

using namespace std;


long long cost[3][100001];

long long getCost(long long leaf, long long initColor, long long nextColor, vector<long long> graph[], long long result[], long long n){
    long long visited[n];
    for(long long  i = 0; i < n; i++){
        visited[i] = 0;
    }
    long long c = cost[initColor - 1][leaf];
    visited[leaf] = 1;
    long long cur = leaf;
    result[leaf] = initColor;
    result[graph[leaf][0]] = nextColor;
    c += cost[nextColor - 1][graph[leaf][0]];
    long long lst1 = initColor;
    long long lst2 = nextColor;
    visited[graph[leaf][0]] = 1;
    cur = graph[leaf][0];

    for(long long i = 0; i < n - 2; i++){
        for(long long j = 0; j < graph[cur].size(); j++){
            if(visited[graph[cur][j]] == 0){
                cur = graph[cur][j];
                visited[cur] = 1;
                c+= cost[6 - lst1 - lst2 - 1][cur];
                result[cur] = 6 - lst1 - lst2;
                long long lst = 6 - lst1 - lst2;
                lst1 = lst2;
                lst2 = lst;
            }
        }
    }
    return c;
}



int main()
{
    ios_base::sync_with_stdio(false);
    long long n;
    cin>>n;
    for(long long i = 0; i < n; i++){
        cin>>cost[0][i];
    }

    for(long long i = 0; i < n; i++){
        cin>>cost[1][i];
    }

    for(long long i = 0; i < n; i++){
        cin>>cost[2][i];
    }


    vector<long long> graph[n];
    for(long long i = 0; i < n; i++){
        vector<long long> v;
        graph[i] = v;
    }
    for(long long i = 0; i < n - 1; i++){
        long long a, b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(long long i = 0; i < n; i++){
        if(graph[i].size() >= 3){
            cout<<-1;
            return 0;
        }
    }

    long long leaf = 0;

    for(long long i = 0; i < n; i++){
        if(graph[i].size() == 1){
            leaf = i;
        }
    }

    long long result[6][n];
    for(long long i = 0; i < 6; i++){
        for(long long j = 0; j < n; j++){
            result[i][j] = 0;
        }
    }

    long long ind = -1;
    long long res = 100000000000000000;
    long long costs[6];
    for(long long i = 0; i < 6; i++){
        costs[i] = 0;
    }
    costs[0] = getCost(leaf, 1, 2, graph, result[0], n);
    costs[1] = getCost(leaf, 1, 3, graph, result[1], n);
    costs[2] = getCost(leaf, 2, 1, graph, result[2], n);
    costs[3] = getCost(leaf, 2, 3, graph, result[3], n);
    costs[4] = getCost(leaf, 3, 1, graph, result[4], n);
    costs[5] = getCost(leaf, 3, 2, graph, result[5], n);


    for(long long i = 0; i < 6; i++){
        if(costs[i] < res){
            res = costs[i];
            ind = i;
        }
    }


    cout<<res<<endl;

    for(long long i = 0; i < n; i++){
        cout<<result[ind][i]<<" ";
    }

    return 0;
}
