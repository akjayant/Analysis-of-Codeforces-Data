#include <bits/stdc++.h>
#define DIM 100007
#define INF 1000000000000000007LL
using namespace std;

long long n,c[4][DIM],ans[DIM];
vector<long long> a[DIM];
long long dfs(int v,int cc,int cp, int par)
{
    long long curr = c[cc][v],ct = 6-cc-cp;
    ans[v] = cc;
    for(auto to:a[v])
    {
        if(to==par) continue;
        curr+=dfs(to,ct,cc,v);
    }
    return curr;
}
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>c[1][i];

    for(int i = 1; i <= n; ++i)
        cin>>c[2][i];

    for(int i = 1; i <= n; ++i)
        cin>>c[3][i];

    for(int i = 1; i < n; ++i)
    {
        int v1,v2;
        cin>>v1>>v2;
        a[v1].push_back(v2);
        a[v2].push_back(v1);
        if(a[v1].size()>2 || a[v2].size()>2) return cout<<-1,0;
    }
    long long root = 1;
    for(int i =1; i <= n; ++i)
        if(a[i].size()==1) root=i;
    long long curr = INF,c1,c2;
    for(int cp = 1; cp <= 3; ++cp)
        for(int cc = 1; cc <= 3; ++cc)
            if(cc!=cp)
    {
        long long rrr = dfs(root,cc,cp,-1);
        if(rrr<curr)
        {
            curr = rrr;
            c1 = cp;
            c2 = cc;
        }
    }
    dfs(root,c2,c1,-1);
    cout<<curr<<endl;
    for(int i = 1; i <= n; ++i)
        cout<<ans[i]<<' ';



    return 0;
}
