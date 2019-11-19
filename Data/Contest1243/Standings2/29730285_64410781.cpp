#include <bits/stdc++.h>

using namespace std;

#define pb push_back


using ll = long long;


const int N=2E5+7;

set<int> T1,T2;
vector<int> ANS;
vector<int> G[N];

void gao(int s)
{
    T1.erase(s);
    queue<int> que;
    int tmp=1;
    que.push(s);
    while(!que.empty())
    {
        int top=que.front();
        que.pop();
        for(int i=0;i<G[top].size();i++)
        {
            int v=G[top][i];
            if(!T1.count(v))
                continue;
            T1.erase(v);
            T2.insert(v);
        }
        for(auto it : T1)
        {
            ++tmp;
            que.push(it);
        }
        T1.swap(T2);
        T2.clear();
    }
    ANS.pb(tmp);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        T1.insert(i);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(T1.count(i))
            gao(i);
    }
    cout<<ANS.size()-1<<"\n";

    return 0;
}