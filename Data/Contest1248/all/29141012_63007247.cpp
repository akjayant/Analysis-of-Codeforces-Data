#include<bits/stdc++.h>
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
using namespace std;
const ll mod=1e9+7;         
const int N=1e6+4;
vector<int> v[N],vr[N];

int visit[N],scc[N],counter;

stack<int> st;

void dfs(int node)
{
    visit[node]=1;
    
    for(int it:v[node])
    if(!visit[it])
    dfs(it);
    
    st.push(node);
}

void dfs1(int node)
{
    visit[node]=1;
    
    scc[node]=counter;
    
    for(int it:vr[node])
    if(!visit[it])
    dfs1(it);
}

void init(int n)
{
    rep(i,1,n+1)
    {
        v[i].clear();
        
        vr[i].clear();
        
        visit[i]=scc[i]=0;
        
        counter=0;
    }
}
int main()                  
{
    int t;
    
    scn(t);
    
    while(t--)
    {
        int n,m;
        
        scn(n);scn(m);
        
        init(n);
        
        rep(i,0,m)
        {
            int a,b;
            
            scn(a);scn(b);
            
            v[a].pb(b);
            
            vr[b].pb(a);
        }
        
        rep(i,1,n+1)
        if(!visit[i])
        dfs(i);
        
        rep(i,1,n+1)
        visit[i]=0;
        
        while(!st.empty())
        {
            int x=st.top();
            
            st.pop();
            
            if(visit[x])
            continue;
            
            counter++;
            
            dfs1(x);
        }
        
        set<int> jury;
        
        rep(i,1,n+1)
        if(scc[i]==counter)
        jury.insert(i);
        
        int sz=(int)jury.size();
        
        if(sz==0||n-sz==0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
            
            printf("%d %d\n",sz,n-sz);
            
            for(auto it:jury)
            printf("%d ",it);
            
            printf("\n");
            
            rep(i,1,n+1)
            if(jury.find(i)==jury.end())
            printf("%d ",i);
            
            printf("\n");
        }
    }
}