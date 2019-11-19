#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
ll c[maxn][5];
vector<int> v[maxn];
int num[maxn];
int a[maxn],b[maxn], cnt=1;
void dfs(int x, int fa)
{
    a[cnt]=x;
    b[x]=cnt;
    cnt++;
    for(int i=0; i<v[x].size(); i++)
    {
        if(v[x][i]==fa) continue;
        else dfs(v[x][i], x);
    }
}
int main()
{
    int n, x, y, z;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>c[i][1];
    for(int i=1; i<=n; i++) cin>>c[i][2];
    for(int i=1; i<=n; i++) cin>>c[i][3];
    for(int i=1; i<n; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        num[x]++;
        num[y]++;
    }
    int flag=1;
    int id=0;
    for(int i=1; i<=n; i++)
    {
        if(num[i]==1) id=i;
        if(num[i]>2) flag=0;
    }
    if(flag==0) cout<<-1<<endl;
    else
    {
        dfs(id, 0);
        ll ans=1e15, sum;
        x=0, y=0, z=0;
        for(int i=1; i<=3; i++)
            for(int j=1; j<=3; j++)
                for(int k=1; k<=3; k++)
                {
                    sum=0;
                    if(i==j || i==k || j==k) continue;
                    for(int p=1; p<=n; p++)
                    {
                        if(p%3==0) sum+=c[a[p]][i];
                        if(p%3==1) sum+=c[a[p]][j];
                        if(p%3==2) sum+=c[a[p]][k];
                    }
                    if(sum<ans) x=i, y=j, z=k, ans=sum;
                }
        cout<<ans<<endl;
        for(int i=1; i<=n; i++)
        {
            int p=b[i];
            if(p%3==0) cout<<x<<" ";
            if(p%3==1) cout<<y<<" ";
            if(p%3==2) cout<<z<<" ";
        }
    }
    return 0;
}

