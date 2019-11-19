#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
vector<int> c[maxn];//猫
vector<int> p[maxn];//人
int n;
int a[maxn];
int deal(int id, int op)
{
    int ans=1;
    if(op==1)
    {
        a[id]=op;
        for(int i=0; i<p[id].size(); i++)
        {
            if(a[p[id][i]]==1) continue;
            if(a[p[id][i]]==2) return 0;
            ans=min(ans,deal(p[id][i], 1));
        }
    }
    if(op==2)
    {
        a[id]=op;
        for(int i=0; i<c[id].size(); i++)
        {
            if(a[c[id][i]]==2) continue;
            if(a[c[id][i]]==1) return 0;
            ans=min(ans,deal(c[id][i], 2));
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int m, x, y;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            c[i].clear();
            p[i].clear();
            a[i]=0;
        }
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            p[x].push_back(y);
            c[y].push_back(x);
        }
        if(deal(1, 1)==1)
        {
            int sum=0;
            for(int i=1; i<=n; i++)
                if(a[i]==1) sum++;
            if(sum!=0 && sum!=n)
            {
                cout<<"Yes\n";
                cout<<sum<<" "<<n-sum<<"\n";
                for(int i=1; i<=n; i++)
                    if(a[i]==1) cout<<i<<" ";
                cout<<"\n";
                for(int i=1; i<=n; i++)
                    if(a[i]!=1) cout<<i<<" ";
                cout<<"\n";
                continue;
            }
        }
        for(int i=1; i<=n; i++)
            a[i]=0;
        if(deal(1, 2)==1)
        {
            int sum=0;
            for(int i=1; i<=n; i++)
                if(a[i]==2) sum++;
            if(sum!=0 && sum!=n)
            {
                cout<<"Yes\n";
                cout<<n-sum<<" "<<sum<<"\n";
                for(int i=1; i<=n; i++)
                    if(a[i]!=2) cout<<i<<" ";
                cout<<"\n";
                for(int i=1; i<=n; i++)
                    if(a[i]==2) cout<<i<<" ";
                cout<<"\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
    return 0;
}
