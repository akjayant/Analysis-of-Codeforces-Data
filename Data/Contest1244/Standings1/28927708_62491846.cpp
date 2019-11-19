#include<bits/stdc++.h>
using namespace std;
vector<int> *tree;
vector<int> chain;
void dfs(int u, int par){
    chain.push_back(u);
    for(int i=0;i<tree[u].size();i++)
    if(tree[u][i]!=par)
    dfs(tree[u][i], u);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
long long cost[3][n+1];
int degree[n+1];
for(int i=1;i<=n;i++)
degree[i]=0;
tree=new vector<int>[n+1];
for(int i=0;i<3;i++)
for(int j=1;j<=n;j++)
cin>>cost[i][j];
bool poss=true;
for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    degree[u]++;
    degree[v]++;
    tree[u].push_back(v);
    tree[v].push_back(u);
  
}
for(int i=1;i<=n;i++)
if(degree[i]>2)
poss=false;
if(!poss)
{cout<<-1;
return 0;}
int start;
for(int i=1;i<=n;i++)
if(degree[i]==1){
start=i;
break;
}

dfs(start, start);

long long final_costs[6];
for(int i=0;i<6;i++)
final_costs[i]=0;
string matrix[6];
matrix[0]="012";
matrix[1]="021";
matrix[2]="102";
matrix[3]="120";
matrix[4]="210";
matrix[5]="201";
for(int i=0;i<6;i++)
for(int j=0;j<n;j++){
    final_costs[i]+=cost[matrix[i][j%3]-'0'][chain[j]];
}
long long minm=1000000000000000000;
for(int i=0;i<6;i++)
minm=min(minm,final_costs[i]);
cout<<minm<<"\n";

int ind;
for(int i=0;i<6;i++)
if(final_costs[i]==minm){
    ind=i;
    break;
}
int ans[n+1];
for(int i=0;i<n;i++)
ans[chain[i]]= (matrix[ind][i%3]-'0')+1;
for(int i=1;i<=n;i++)
cout<<ans[i]<<" ";

}