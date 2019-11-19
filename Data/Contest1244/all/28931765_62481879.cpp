#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5+100;

int a[3][maxn];
vector <int> edge[maxn];
int vis[maxn];
vector <int> v;
void dfs(int x)
{
    vis[x]=1;
    v.push_back(x);
    for(int i=0;i<edge[x].size();i++)
    {
        if(!vis[edge[x][i]]) dfs(edge[x][i]);
    }
}
int b[]={0,1,2};
int main()
{
    int n,m,i,j,k,x,y;
    int T;
    T=1;
    while(T--)
    {
        scanf("%d",&n);
        for(j=0;j<3;j++)
        {
            for(i=1;i<=n;i++)
            {
                scanf("%d",&a[j][i]);
            }
        }
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        int st=-1,ne;
        for(i=1;i<=n;i++)
        {
            if(edge[i].size()==1) st=i;
            else if(edge[i].size()>2)
            {
                printf("-1\n");
                return 0;
            }
        }
        dfs(st);
//        for(i=0;i<n;i++)
//        {
//            printf("%d ",v[i]);
//        }printf("\n");
        LL ans=1e18;
        x=0;
        y=0;
        do{
            LL sum=0;
            for(i=0;i<n;i++)
            {
                sum+=a[b[i%3]][v[i]];
                //cout<<"+"<<a[b[i%3]][v[i]];
            }
            //printf("\n");
            if(ans>sum)
            {
                ans=sum;
                y=x;
            }
            x++;
        }while(next_permutation(b,b+3));
        printf("%I64d\n",ans);
        x=0;
        do{
            if(x==y)
            {
                break;
            }
            x++;
        }while(next_permutation(b,b+3));
        for(i=0;i<n;i++)
        {
            vis[v[i]]=b[i%3]+1;
        }
        for(i=1;i<=n;i++)
        {
            printf("%d ",vis[i]);
        }
        printf("\n");
    }
    return 0;
}

/**
4
0 1 2 2
1 10 100 1000
*/
