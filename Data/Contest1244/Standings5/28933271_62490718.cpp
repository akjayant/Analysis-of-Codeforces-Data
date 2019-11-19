#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll leaf,n;
ll ar[100002],br[100002],cr[100002],col[100002],col1[100002];
vector<vector<ll> > vec(100002);
ll func(ll x1,ll x2,ll x3)
{
    ll visit[n+1]={0},s=0;
    ll i=leaf;
    ll arr[4];
    arr[1]=x1;
    arr[2]=x2;
    arr[3]=x3;
    ll j=1;
    visit[i]=1;
    while(1)
    {
       //cout<<i<<"\n";
       if(arr[j]==1)
       {
           s+=ar[i];
           col1[i]=1;
       }
       if(arr[j]==2)
       {
           s+=br[i];
           col1[i]=2;
       }
       if(arr[j]==3)
       {
           s+=cr[i];
           col1[i]=3;
       }
       j++;
       if(j==4)
        j=1;
       if(i!=leaf && vec[i].size()==1)
            break;
       ll z1;
       for(auto it=vec[i].begin();it!=vec[i].end();it++)
       {
           if(visit[*it]==0)
           {
               visit[*it]=1;
               z1=*it;
           }
       }
       i=z1;
    }
    //cout<<s<<"\n";
    return s;
}
int main()
{
    ll i,x,y,min1,s=0;
    cin>>n;
    ll cnt[n+1]={0};
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>br[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>cr[i];
    }
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        cnt[x]++;
        cnt[y]++;
    }
    for(i=1;i<=n;i++)
    {
        if(cnt[i]==1)
        {
            leaf=i;
            s++;
        }
    }
    //cout<<leaf<<" "<<s<<"\n";
    if(s>2)
        cout<<"-1";
    else
    {
        min1=func(1,2,3);
        for(i=1;i<=n;i++)
        {
            col[i]=col1[i];
        }
        if(min1>func(1,3,2))
        {
            min1=min(min1,func(1,3,2));
            for(i=1;i<=n;i++)
            {
                col[i]=col1[i];
            }
        }
        if(min1>func(2,3,1))
        {
            min1=min(min1,func(2,3,1));
            for(i=1;i<=n;i++)
            {
                col[i]=col1[i];
            }
        }
        if(min1>func(3,2,1))
        {
            min1=min(min1,func(3,2,1));
            for(i=1;i<=n;i++)
            {
                col[i]=col1[i];
            }
        }
        if(min1>func(3,1,2))
        {
            min1=min(min1,func(3,1,2));
            for(i=1;i<=n;i++)
            {
                col[i]=col1[i];
            }
        }
        if(min1>func(2,1,3))
        {
            min1=min(min1,func(2,1,3));
            for(i=1;i<=n;i++)
            {
                col[i]=col1[i];
            }
        }

        cout<<min1<<"\n";
        for(i=1;i<=n;i++)
        {
            cout<<col[i]<<" ";
        }
    }
}
