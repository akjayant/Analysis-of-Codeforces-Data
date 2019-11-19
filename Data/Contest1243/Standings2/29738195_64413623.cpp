#include <bits/stdc++.h>
using namespace std;
const int N=(int)(2e5+12);
int n,m,k,cnt[N],x,y,i;
unordered_map<int, bool>u[N];
bitset<N> bit;
void dfs(int v){
    bit[v]=0,    cnt[k]++;
    for(int i=bit._Find_first();i<bit.size();i=bit._Find_next(i)) if(!u[v][i])dfs(i);
}
int main(){
    ios_base::sync_with_stdio(NULL);
    cin>>n>>m;
    for(i=1;i<=n;++i)bit[i] =1;
    for(i=1;i<=m;++i)cin>>x>>y,u[x][y]=u[y][x] =1;
    for(i=1;i<=n;++i)if(bit[i])dfs(i),k++;
    cout<<k-1<<'\n';
    //sort(cnt,cnt+k);
}