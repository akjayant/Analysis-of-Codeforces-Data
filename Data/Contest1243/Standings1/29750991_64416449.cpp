#include<bits/stdc++.h>
#define mset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=1e5+10;
vector<int> g[N];
set<int> cost0,cost1;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
        cost1.insert(i);
    for(int i=1;i<=n;++i)
        sort(g[i].begin(),g[i].end());
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        int u;
        if(cost0.size()!=0)
        {
            u=*cost0.begin();
            cost0.erase(cost0.begin());
        }
        else{
            sum++;
            u=*cost1.begin();
            cost1.erase(cost1.begin());
        }
//        printf("u:%d\n",u);
        for(auto it=cost1.begin();it!=cost1.end();)
        {
            int v=*it;
            int th=lower_bound(g[u].begin(),g[u].end(),v) - g[u].begin();
//            printf("v:%d, th:%d\n",v,th);
            if(th < int(g[u].size())&& g[u][th]==v) it++;
            else{
//                printf("erase and add 0  v:%d\n",v);
                cost1.erase(it++);
                cost0.insert(v);
            }
        }
    }
    printf("%d\n",sum-1);
    return 0;

}
