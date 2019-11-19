#include<bits/stdc++.h>
using namespace std;
set<int> s;
int n;
vector<int> *graph;
void dfs(int u){
vector<int> children;
int l=1;
for(int i=0;i<graph[u].size();i++){
int r=graph[u][i]-1;
if(l<=r)
{set<int> ::iterator x,y;
x=s.lower_bound(l);
y=s.upper_bound(r);
for(set<int> ::iterator j=x;j!=y;++j){
children.push_back(*j);
}
}
l=graph[u][i]+1;
}
 
if(l<=n){
    {set<int> ::iterator x,y;
x=s.lower_bound(l);
y=s.upper_bound(n);
for(set<int> ::iterator j=x;j!=y;++j){
children.push_back(*j);
}
 
}
 
}
 
for(int i=0;i<children.size();i++)
s.erase(children[i]);
for(int i=0;i<children.size();i++)
dfs(children[i]);
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int m;
cin>>n>>m;
graph = new vector<int>[n+1];
int u,v;
for(int i=0;i<m;i++){
    cin>>u>>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
}
for(int i=1;i<=n;i++)
sort(graph[i].begin(), graph[i].end());
for(int i=1;i<=n;i++)
s.insert(i);
vector<int> sizes;
int prev_size=n;
while(!s.empty()){
int a=*s.begin();
s.erase(s.begin());
dfs(a);
sizes.push_back(prev_size-s.size());
prev_size=s.size();
}
cout<<sizes.size()-1;
 
}
