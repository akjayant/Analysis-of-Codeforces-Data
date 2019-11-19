#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD=1e9+7;
 
//const int MOD=998244353;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    int n;
    cin>>n;
    
    vector<vector<int>> tree(n+1), cols(4,vector<int>(n+1));
    
    for(int i=1; i<=3; i++){
        for(int j=1; j<=n; j++){
            cin>>cols[i][j];
        }
    }
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    
    for(int i=1; i<=n ;i++){
        if(tree[i].size()>=3){
            cout<<-1;
            return 0;
        }
    }
    
    vector<int> order;
    int st=0;
    for(int i=1; i<=n; i++){
        if(tree[i].size()==1){
            st=i;
            break;
        }
    }
    vector<bool> vis(n+1,0);
    queue<int> q;
    q.push(st);
    vis[st]=1;
    while(q.size()){
        int cur=q.front();
        //cout<<cur<<'\n';
        q.pop();
        order.push_back(cur);
        for(int j:tree[cur]){
            if(!vis[j]){
                q.push(j);
                vis[j]=1;
            }
        }
    }
    
    /*
    for(int i:order){
        cout<<i<<' ';
    }
    */
    long long ba=1e18;
    vector<int> bp={1,2,3}, cp{1,2,3};
    
    do{
        long long cost=0;
        for(int i=0; i<n; i++){
            cost+=cols[cp[(i%3)]][order[i]];
        }
        
        if(cost<ba){
            ba=cost;
            bp=cp;
        }
        
    }while(next_permutation(cp.begin(),cp.end()));
    cout<<ba<<'\n';
    vector<int> ans(n+1);
    for(int i=0; i<n; i++){
        ans[order[i]]=bp[(i%3)];
    }
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    
    
    
    
    
    
    return 0;
}
