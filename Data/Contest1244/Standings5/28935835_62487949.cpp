#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
    int n;
    scanf("%lld",&n);
    assert(n >= 3);
    int a[n+1][3];
    for (int i = 0; i < 3; i++){
        for (int j = 1; j <= n; j++){
            scanf("%lld",&a[j][i]);
        }
    }
    int root;
    vector<int> adjlist[n+1];
    for (int i = 0; i < n-1; i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        if (adjlist[i].size() > 2){
            printf("-1");
            return 0;
        }
        else if (adjlist[i].size() == 1){
            root = i;
        }
    }
    vector<int> group[3];
    int cur = adjlist[root][0];
    int last = root;
    group[0].push_back(root);
    group[1].push_back(cur);
    int id = 2;
    while (adjlist[cur].size() == 2){
        if (adjlist[cur][0] == last) swap(adjlist[cur][0],adjlist[cur][1]);
        last = cur;
        cur = adjlist[cur][0];
        group[id].push_back(cur);
        id = (id+1)%3;
    }
    int cost[3][3]; memset(cost,0,sizeof(cost));
    for (int i = 0; i < 3; i++){
        for (auto x : group[i]){
            cost[i][0] += a[x][0];
            cost[i][1] += a[x][1];
            cost[i][2] += a[x][2];
        }
        //printf("%lld %lld %lld\n",cost[i][0],cost[i][1],cost[i][2]);
    }
    int op[6];
    op[0] = cost[0][0] + cost[1][1] + cost[2][2];
    op[1] = cost[0][0] + cost[1][2] + cost[2][1];
    op[2] = cost[0][1] + cost[1][0] + cost[2][2];
    op[3] = cost[0][1] + cost[1][2] + cost[2][0];
    op[4] = cost[0][2] + cost[1][0] + cost[2][1];
    op[5] = cost[0][2] + cost[1][1] + cost[2][0];
    int m = min(op[0],min(op[1],min(op[2],min(op[3],min(op[4],op[5])))));
    int ans[n+1];
    if (op[0] == m){
        for (auto x : group[0]) ans[x] = 1;
        for (auto x : group[1]) ans[x] = 2;
        for (auto x : group[2]) ans[x] = 3;
    }
    else if (op[1] == m){
        for (auto x : group[0]) ans[x] = 1;
        for (auto x : group[1]) ans[x] = 3;
        for (auto x : group[2]) ans[x] = 2;
    }
    else if (op[2] == m){
        for (auto x : group[0]) ans[x] = 2;
        for (auto x : group[1]) ans[x] = 1;
        for (auto x : group[2]) ans[x] = 3;
    }
    else if (op[3] == m){
        for (auto x : group[0]) ans[x] = 2;
        for (auto x : group[1]) ans[x] = 3;
        for (auto x : group[2]) ans[x] = 1;
    }
    else if (op[4] == m){
        for (auto x : group[0]) ans[x] = 3;
        for (auto x : group[1]) ans[x] = 1;
        for (auto x : group[2]) ans[x] = 2;
    }
    else if (op[5] == m){
        for (auto x : group[0]) ans[x] = 3;
        for (auto x : group[1]) ans[x] = 2;
        for (auto x : group[2]) ans[x] = 1;
    }
    printf("%lld\n",m);
    for (int i = 1; i <= n; i++){
        printf("%lld ",ans[i]);
    }


}
