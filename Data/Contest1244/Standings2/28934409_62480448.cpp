#include <bits/stdc++.h>

using namespace std;

long long x[3][100100],a,l,p,kol[1001000],w,w1,poc;
vector <int >m[1001000];
void dfs(int poz,int pier,int dwa,int trzy,int cza,int oj)
{
    if(cza%3==0)
    {
        w+=x[pier][poz];
    }
    else if(cza%3==1)
    {
        w+=x[dwa][poz];
    }
    else
    {
        w+=x[trzy][poz];
    }

    for(int i=0; i<m[poz].size(); i++)
    {
        if(m[poz][i]!=oj)
        {
            dfs(m[poz][i],pier,dwa,trzy,cza+1,poz);
        }
    }
    if(w<w1)
    {
        if(cza%3==0)
        {
            kol[poz]=pier+1;
        }
        else if(cza%3==1)
        {
            kol[poz]=dwa+1;
        }
        else
        {
            kol[poz]=trzy+1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    for(int i=0; i<a; i++)
    {
        cin>>x[0][i];
    }
    for(int i=0; i<a; i++)
    {
        cin>>x[1][i];
    }

    for(int i=0; i<a; i++)
    {
        cin>>x[2][i];
    }
    for(int i=0; i<a-1; i++)
    {
        cin>>l>>p;
        l--;
        p--;
        m[l].push_back(p);
        m[p].push_back(l);
    }
    for(int i=0; i<a; i++)
    {
        if(m[i].size()==1)
        {
            poc=i;
        }
        if(m[i].size()>2)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    w=0;
    w1=1000LL*1000*1000*1000*1000*1000;
    dfs(poc,0,1,2,0,-1);
    w1=min(w,w1);
    w=0;
    dfs(poc,0,2,1,0,-1);
    w1=min(w,w1);
    w=0;
    dfs(poc,1,0,2,0,-1);
    w1=min(w,w1);
    w=0;
    dfs(poc,1,2,0,0,-1);
    w1=min(w,w1);
    w=0;
    dfs(poc,2,0,1,0,-1);
    w1=min(w,w1);
    w=0;
    dfs(poc,2,1,0,0,-1);
    w1=min(w,w1);
    cout<<w1<<"\n";
    for(int i=0; i<a; i++)
    {
        cout<<kol[i]<<" ";
    }
    return 0;
}
