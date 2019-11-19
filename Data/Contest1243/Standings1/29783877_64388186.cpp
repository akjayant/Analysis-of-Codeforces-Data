#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
vector<int> G[N];
set<int> st1,st2;
int id[N];
int n;
void bfs(int x,int num)
{
    st1.clear();st2.clear();
    for(int i=1;i<=n;++i)
        if(x!=i&&id[i]==0)
            st1.insert(i);
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        id[x]=num;
        for(int y:G[x])
        {
            auto t=st1.erase(y);
            if(t) st2.insert(y);
        }
        for(int y:st1)
            q.push(y);
        swap(st1,st2);
        st2.clear();
    }
}

int main() {
    int m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int cnt=0;
    for(int i=1;i<=n;++i)
        if(!id[i])
            bfs(i,++cnt);
    printf("%d\n",cnt-1);
    return 0;
}
