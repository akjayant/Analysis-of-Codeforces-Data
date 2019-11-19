#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> edge[100100];
long long cost[100100][3];
long long ans[3][3];
bool check[100100];
long long fuck=100000000000000000;
int color[100100];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&cost[j][i]);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int start=-1;
    for(int i=1;i<=n;i++)
    {
        if(edge[i].size()>2)
        {
            cout<<"-1";
            return 0;
        }
        if(edge[i].size()==1)
            start=i;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i==j)
                continue;
            for(int k=1;k<=n;k++)
                check[k]=false;
            int ind=start;
            int precol=i;
            int col=j;
            for(int k=0;k<n;k++)
            {
                ans[i][j]+=cost[ind][3-precol-col];
                check[ind]=true;
                int tmp=precol;
                precol=col;
                col=3-tmp-col;
                int nind=edge[ind][0];
                if(check[edge[ind][0]])
                    nind=edge[ind][1];
                ind=nind;
            }
            if(fuck>ans[i][j])
            {
                fuck=ans[i][j];
                for(int k=1;k<=n;k++)
                    check[k]=false;
                precol=i;
                col=j;
                ind=start;
                for(int k=0;k<n;k++)
                {
                    color[ind]=3-precol-col;
                    check[ind]=true;
                    precol=col;
                    col=color[ind];
                    int nind=edge[ind][0];
                    if(check[edge[ind][0]])
                        nind=edge[ind][1];
                    ind=nind;
                }
            }
        }
    }
    cout<<fuck<<"\n";
    for(int i=1;i<=n;i++)
        cout<<color[i]+1<<" ";
}
