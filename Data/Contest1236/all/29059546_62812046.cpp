#include <bits/stdc++.h>
using namespace std;

long long k,n,m;

vector < long long > li[100005];
vector < long long > co[100005];

long long cauta_1(long long x,long long y)
{
    long long st=1,dr=li[x].size(),mij=(st+dr)/2,sol=m+1;
    while(st<=dr)
    {
        if(li[x][mij-1]>y)
        {
            sol=li[x][mij-1];
            dr=mij-1;
        }
        else
            st=mij+1;
        mij=(st+dr)/2;
    }
    return sol;
}

long long cauta_2(long long x,long long y)
{
    long long st=1,dr=co[y].size(),mij=(st+dr)/2,sol=n+1;
    while(st<=dr)
    {
        if(co[y][mij-1]>x)
        {
            sol=co[y][mij-1];
            dr=mij-1;
        }
        else
            st=mij+1;
        mij=(st+dr)/2;
    }
    return sol;
}

long long cauta_3(long long x,long long y)
{
    long long st=1,dr=li[x].size(),mij=(st+dr)/2,sol=0;
    while(st<=dr)
    {
        if(li[x][mij-1]<y)
        {
            sol=li[x][mij-1];
            st=mij+1;
        }
        else
            dr=mij-1;
        mij=(st+dr)/2;
    }
    return sol;
}

long long cauta_4(long long x,long long y)
{
    long long st=1,dr=co[y].size(),mij=(st+dr)/2,sol=0;
    while(st<=dr)
    {
        if(co[y][mij-1]<x)
        {
            sol=co[y][mij-1];
            st=mij+1;
        }
        else
            dr=mij-1;
        mij=(st+dr)/2;
    }
    return sol;
}


int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        long long  x,y;
        cin>>x>>y;
        li[x].push_back(y);
        co[y].push_back(x);
    }
    for(int i=1;i<=max(n,m);i++)
    {
        sort(li[i].begin(),li[i].end());
        sort(co[i].begin(),co[i].end());
    }
    long long  dir=1;
    long long x=1,y=1,viz=0,limn,lime,limv,lims;
    bool ok = true;
    limn=1;
    lime=m+1;
    lims=n+1;
    limv=0;
    while(ok == true)
    {
        long long vizpas=0;
        if(dir==1)
        {
            vizpas=min(cauta_1(x,y),lime)-1-y;
            lime=y+vizpas;
            y=lime;
            dir=2;
        }
        else
        if(dir==2)
        {
            vizpas=min(cauta_2(x,y),lims)-1-x;
            lims=x+vizpas;
            x=lims;
            dir=3;
        }
        else
        if(dir==3)
        {
            vizpas=y-max(cauta_3(x,y),limv)-1;
            limv=y-vizpas;
            y=limv;
            dir=4;
        }
        else
        if(dir==4)
        {
            vizpas=x-max(cauta_4(x,y),limn)-1;
            limn=x-vizpas;
            x=limn;
            dir=1;
        }
        viz+=vizpas;
        if(vizpas==0)
            ok = false;
        if(x==1&&y==1&&vizpas==0&&dir==2)
            ok = true;
    }
    if(viz+1!=n*m-k)
        cout<<"No";
    else
        cout<<"Yes";
        return 0;
}
