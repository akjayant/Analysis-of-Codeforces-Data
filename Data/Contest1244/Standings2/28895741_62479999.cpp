#include <bits/stdc++.h>
using namespace std;
 
long long int c[100001][3];
 
vector<int> g[100001];

long long int dfs(int u,int prev,int col,int add){
    long long int ans = c[u][col];
    for(auto i:g[u]){
        if(i!=prev){
            ans += dfs(i,u,(col+add)%3,add);
        }
    }
    return ans;   
}
 
int mark[100001];
void cool(int u,int prev,int col,int add){
    mark[u]=col;
    for(auto i:g[u]){
        if(i!=prev){
            cool(i,u,(col+add)%3,add);
        }
    }
}
 
int main() {
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    int n;
    cin >> n;
    for(int j=0;j<3;j++)
        for(int i=1;i<=n;i++){
            cin >> c[i][j];
        }
    
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int v;
    for(int i=1;i<=n;i++){
        if(g[i].size()>=3){
            cout << "-1";
            return 0;
        }
        if(g[i].size()==1) v=i;
    }
 
    long long int ans = 10000000000000000;
    int x,y;
    for(int col=0;col<3;col++){
        for(int add=1;add<=2;add++){
            long long int temp = dfs(v,-1,col,add);
            if(temp<ans){
                ans=temp;
                x=col;
                y=add;
            }
        }
    }
    cout << ans << endl;
 
    cool(v,-1,x,y);
    for(int i=1;i<=n;i++){
        cout << mark[i]+1 << " ";
    }
   
 
}