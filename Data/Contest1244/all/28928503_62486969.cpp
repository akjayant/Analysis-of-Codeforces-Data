#include<bits/stdc++.h>
using namespace std;


const int MX = (1<<20);

vector < int > v[MX];

int cost[3][MX];

vector < int > nodes;

void dfs(int x , int p){
    nodes.push_back(x);
    for(auto nxt : v[x]){
        if(nxt == p) continue;
        dfs(nxt , x);
    }
}
int main() {
    // freopen("exptree.in","r",stdin);
    int n;
    scanf("%d", &n);
    for(int col = 0 ; col < 3 ; col++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[col][j]);
        }
    }
    for(int j = 1 ; j < n ; j++){
        int a , b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int o = 0 , t = 0 , any = 0;
    for(int j = 1 ; j <= n ; j++){
        if(v[j].size() == 1){
            any = j;
            o++;
        }
        else{
            t++;
        }
    }
    if(o == 2 && t == n - 2);

    else{
        cout<<-1<<endl;
        return 0;
    }

    dfs(any , -1);

    int perm[] = {0 , 1 , 2};

    vector < int > sol;
    sol.resize(n + 1);
    long long ans = (1ll<<60) , cur;
    do{
      //  cout<<perm[0]<<' '<<perm[1]<<' '<<perm[2]<<endl;
        cur = 0;
        for(int j = 0 ; j < n ; j++){
            cur += cost[perm[j % 3]][nodes[j]];
        }
        if(cur < ans){
            ans = cur;
            for(int j = 0 ; j < n ; j++)
                sol[nodes[j]] = perm[j % 3] + 1;
        }
       // cout<<cur<<endl;
    } while(next_permutation(perm , perm + 3));

    cout<<ans<<endl;
    for(int j = 1 ; j <= n ; j++) cout<<sol[j]<<' ';

}