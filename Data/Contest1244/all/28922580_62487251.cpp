#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;
const LL MOD=1e9+7;



struct Vertex
{
    int c[3];
    int deg=0;
    vector<int> nbs;
};
Vertex vers[200009];
int visited[200009];
LL answer[3][2];
int patt[3][2][3];
void DFS(int u, int step)
{
    visited[u]=step+1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            answer[i][j]+=vers[u].c[patt[i][j][step%3]];
        }
    }
    for(auto idx : vers[u].nbs)
    {
        if(!visited[idx])
        {
            DFS(idx,step+1);
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

        int n;
        cin>>n;
    int temp;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        vers[i].c[0]=temp;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        vers[i].c[1]=temp;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        vers[i].c[2]=temp;
    }
    int a,b;
    bool ans=true;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        vers[a].nbs.push_back(b);
        vers[b].nbs.push_back(a);

        if(++vers[a].deg>2)
        {
            ans=false;
        }
        if(++vers[b].deg>2)
        {
            ans=false;
        }
    }
    int u;
    for(int i=1;i<=n;i++)
    {
        if(vers[i].deg==1)
        {
            u=i;
        }
    }
    if(ans)
    {
        for(int i=0;i<3;i++)
        {
            //answer[i][0]=vers[u].c[i]+vers[v].c[(i+1)%3];
            //answer[i][1]=vers[u].c[i]+vers[v].c[(i+2)%3];
            for(int j=0;j<2;j++)
            {
                patt[i][j][0]=i;
                patt[i][j][1]=(i+j+1)%3;
                for(int k=0;k<3;k++)
                {
                    if(k!=patt[i][j][0] &&k!=patt[i][j][1])
                    {
                        patt[i][j][2]=k;
                    }
                }
            }
        }
        DFS(u,0);
        PII minn={0,0};
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(answer[minn.first][minn.second]>answer[i][j])
                {
                    minn={i,j};
                }
            }
        }
        cout<<answer[minn.first][minn.second]<<'\n';
        for(int i=1;i<=n;i++)
        {
            cout<<patt[minn.first][minn.second][(visited[i]-1)%3]+1<<" ";
        }
    }
    else
    {
        cout<<-1;
    }
}
