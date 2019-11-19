#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b,d,mi=1000000000000000000,e=-1,f,g;
    cin>>n;
    int A1[n],A2[n],A3[n];
    for(int i=0; i<n; i++)cin>>A1[i];
    for(int i=0; i<n; i++)cin>>A2[i];
    for(int i=0; i<n; i++)cin>>A3[i];
    vector<vector<int> >v(n);
    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    for(int i=0; i<n; i++){if(v[i].size()>2){cout<<-1; return 0;}if(v[i].size()==1&&e!=-1)f=i;if(v[i].size()==1&&e==-1)e=i;}
    vector<int>p;
    p.push_back(e);
    int u=e;
    while(u!=f)
    {
        if(p.size()>1&&v[u][0]==p[p.size()-2])u=v[u][1];
        else u=v[u][0];
        p.push_back(u);
    }
    long long s=0;
    for(int i=0; i<n; i++)
    {
        if(i%3==0)s+=A1[p[i]];
        if(i%3==1)s+=A2[p[i]];
        if(i%3==2)s+=A3[p[i]];
    }
    if(s<=mi)
    {
        mi=s;
        g=1;
    }
    s=0;
    for(int i=0; i<n; i++)
    {
        if(i%3==0)s+=A1[p[i]];
        if(i%3==1)s+=A3[p[i]];
        if(i%3==2)s+=A2[p[i]];
    }
    if(s<=mi)
    {
        mi=s;
        g=2;
    }
    s=0;
    for(int i=0; i<n; i++)
    {
        if(i%3==0)s+=A2[p[i]];
        if(i%3==1)s+=A1[p[i]];
        if(i%3==2)s+=A3[p[i]];
    }
    if(s<=mi)
    {
        mi=s;
        g=3;
    }
    s=0;
    for(int i=0; i<n; i++)
    {
        if(i%3==0)s+=A2[p[i]];
        if(i%3==1)s+=A3[p[i]];
        if(i%3==2)s+=A1[p[i]];
    }
    if(s<=mi)
    {
        mi=s;
        g=4;
    }
    s=0;
    for(int i=0; i<n; i++)
    {
        if(i%3==0)s+=A3[p[i]];
        if(i%3==1)s+=A1[p[i]];
        if(i%3==2)s+=A2[p[i]];
    }
    if(s<=mi)
    {
        mi=s;
        g=5;
    }
    s=0;
    for(int i=0; i<n; i++)
    {
        if(i%3==0)s+=A3[p[i]];
        if(i%3==1)s+=A2[p[i]];
        if(i%3==2)s+=A1[p[i]];
    }
    if(s<=mi)
    {
        mi=s;
        g=6;
    }
    vector<int>vk(n);
    if(g==1)
    {
        for(int i=0; i<n; i++)
        {
            if(i%3==0)vk[p[i]]=1;
            if(i%3==1)vk[p[i]]=2;
            if(i%3==2)vk[p[i]]=3;
        }
        cout<<mi<<endl;
        for(int i=0; i<n; i++)cout<<vk[i]<<" ";
    }
    if(g==2)
    {
        for(int i=0; i<n; i++)
        {
            if(i%3==0)vk[p[i]]=1;
            if(i%3==1)vk[p[i]]=3;
            if(i%3==2)vk[p[i]]=2;
        }
        cout<<mi<<endl;
        for(int i=0; i<n; i++)cout<<vk[i]<<" ";
    }
    if(g==3)
    {
        for(int i=0; i<n; i++)
        {
            if(i%3==0)vk[p[i]]=2;
            if(i%3==1)vk[p[i]]=1;
            if(i%3==2)vk[p[i]]=3;
        }
        cout<<mi<<endl;
        for(int i=0; i<n; i++)cout<<vk[i]<<" ";
    }
    if(g==4)
    {
        for(int i=0; i<n; i++)
        {
            if(i%3==0)vk[p[i]]=2;
            if(i%3==1)vk[p[i]]=3;
            if(i%3==2)vk[p[i]]=1;
        }
        cout<<mi<<endl;
        for(int i=0; i<n; i++)cout<<vk[i]<<" ";
    }
    if(g==5)
    {
        for(int i=0; i<n; i++)
        {
            if(i%3==0)vk[p[i]]=3;
            if(i%3==1)vk[p[i]]=1;
            if(i%3==2)vk[p[i]]=2;
        }
        cout<<mi<<endl;
        for(int i=0; i<n; i++)cout<<vk[i]<<" ";
    }
    if(g==6)
    {
        for(int i=0; i<n; i++)
        {
            if(i%3==0)vk[p[i]]=3;
            if(i%3==1)vk[p[i]]=2;
            if(i%3==2)vk[p[i]]=1;
        }
        cout<<mi<<endl;
        for(int i=0; i<n; i++)cout<<vk[i]<<" ";
    }
}
