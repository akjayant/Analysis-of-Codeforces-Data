#include <bits/stdc++.h>
#define MAX 100006
using namespace std;

set<int> adj[MAX];
vector<int> nadj[MAX];
bool mark[MAX];
int next[MAX];
int n, m;

void dfs( int cur ){
    mark[cur] = true;
    for( int i = 0; i < nadj[cur].size(); i++ ){
        int u = nadj[cur][i];
        if(!mark[u])
            dfs(u);
    }
}

int main(){
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for( int i = 0; i < n; i++ ){
        int two = 2;
        for( int jj = 0; jj < n; jj++ ){
            int j = (i + jj) % n;
            if( i != j && adj[i].count(j) == 0 ){
                nadj[i].push_back(j);
                nadj[j].push_back(i);
                //cout << "yal = " << i << " " << j << endl;
                two--;
                if(two == 0)
                    break;
            }
        }
    }
    //cout << "HFDFDF " << endl;
    int comp = 0;
    for( int i = 0; i < n; i++ )
        if(!mark[i]){
            comp++;
            dfs(i);
        }
    cout << comp - 1 << endl;

    return 0;
}