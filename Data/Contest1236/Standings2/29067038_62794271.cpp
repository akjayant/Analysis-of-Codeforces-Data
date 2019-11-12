#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define mk(a,b) make_pair(a,b)

priority_queue<pair<pr,int > >Q;
vector<int>ans[305];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        Q.push(mk(mk(0,0),i));
    }
    for(int i=n*n;i>=1;i--){
        int now=Q.top().second;
        Q.pop();
        ans[now].push_back(i);
        Q.push(mk(mk(-ans[now].size(),-i),now));
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<ans[i].size();j++)printf("%d ",ans[i][j]);
        puts("");
    }
}
