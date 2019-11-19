#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> mg[100005],t[100005];
int pom[100005],ma[100005],marka[100005];

void dfs(int cvor)
{
    int i,x; marka[cvor]=1;
    for(i=0;i<t[cvor].size();i++)
    {
        x=t[cvor][i];
        if(marka[x]==0) dfs(x);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int n,m,i,j,k,a,b,res=0,mini,v,x;

    cin>>n>>m;

    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        mg[a].push_back(b);
        mg[b].push_back(a);
    }


      mini=n; v=0;
     for(i=1;i<=n;i++)
     {
        if(mg[i].size()<mini) {mini=mg[i].size(); v=i;}
     }

     for(i=0;i<mg[v].size();i++)
     {
         x=mg[v][i];
         ma[x]=1;
     }

     for(i=1;i<=n;i++)
     {
        if(i==v) continue;
        else if(ma[i]==0)
        {
            t[v].push_back(i);
            t[i].push_back(v);
        }
    }



     for(a=1;a<=n;a++)
     {
         if(ma[a]==1)
         {
             for(j=1;j<=n;j++) pom[j]=0;
             for(i=0;i<mg[a].size();i++)
             {
                 x=mg[a][i];
                 pom[x]=1;
             }

             for(i=1;i<=n;i++)
             {
                 if(i==a) continue;
                 else if(pom[i]==0)
                 {
                     t[a].push_back(i);
                     t[i].push_back(a);
                 }
             }
         }
     }


     for(i=1;i<=n;i++)
     {
         if(marka[i]==0)
         {
             res++;
             dfs(i);
         }
     }

     cout<<res-1<<endl;

    return 0;
}
