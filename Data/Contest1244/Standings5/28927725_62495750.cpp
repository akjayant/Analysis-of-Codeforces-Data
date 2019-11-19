#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
using namespace std;
#define PI 3.14159265
#define mod 1000000007
#define ex exit(0)
#define For for(i=0;i<n;++i)
ll Min(ll a,ll b)
{
    if(a>=b)
        return b;
    else
        return a;
}
ll Max(ll a,ll b)
{
    if(a>=b)
        return a;
    else
        return b;
}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i;
    cin>>n;
    vll a(n),b(n),c(n);
    For{
        cin>>a[i];
    }
    For{
        cin>>b[i];
    }
    For{
        cin>>c[i];
    }
    vector<vector<ll>> g(n+1);
    for(i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(g[u].size()>2||g[v].size()>2)
        {
            cout<<-1;
            exit(0);
        }
    }
    ll f1=0,f2=0,o=0;
    for(i=1;i<=n;i++)
    {
        if(g[i].size()==1){
            o++;
            if(o==1)
                f1=i;
            else if(o==2)
                f2=i;
        }
    }
        vll v(n+1,0);
    vll ans(n+1);
    if(o==2)
    {
        ll x1=0,x2=0,x3=0,x4=0,x5=0,x6=0;
        ll s=f1,m=0;
        vll visited(n+1,0);
        while(s!=f2)
        {
            if(m==0)
                x1+=a[s-1];
            else if(m==1)
                x1+=b[s-1];
            else
                x1+=c[s-1];
            m++;
            m%=3;
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }
        if(m==0)
            x1+=a[s-1];
        else if(m==1)
            x1+=b[s-1];
        else
            x1+=c[s-1];
        
        s=f1,m=1;
        visited=v;
        while(s!=f2)
        {
            if(m==0)
                x2+=a[s-1];
            else if(m==1)
                x2+=b[s-1];
            else
                x2+=c[s-1];
            m++;
            m%=3;
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }
        if(m==0)
            x2+=a[s-1];
        else if(m==1)
            x2+=b[s-1];
        else
            x2+=c[s-1];
        
        s=f1,m=2;
        visited=v;
        while(s!=f2)
        {
            if(m==0)
                x3+=a[s-1];
            else if(m==1)
                x3+=b[s-1];
            else
                x3+=c[s-1];
            m++;
            m%=3;
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }
        if(m==0)
            x3+=a[s-1];
        else if(m==1)
            x3+=b[s-1];
        else
            x3+=c[s-1];
        
        
        s=f1,m=0;
        visited=v;
        while(s!=f2)
        {
            if(m==0)
                x4+=a[s-1];
            else if(m==1)
                x4+=b[s-1];
            else
                x4+=c[s-1];
            if(m==0)
                m=2;
            else if(m==2)
                m=1;
            else
                m=0;
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }
        if(m==0)
            x4+=a[s-1];
        else if(m==1)
            x4+=b[s-1];
        else
            x4+=c[s-1];
        
        
        s=f1,m=1;
        visited=v;
        while(s!=f2)
        {
            if(m==0)
                x5+=a[s-1];
            else if(m==1)
                x5+=b[s-1];
            else
                x5+=c[s-1];
            if(m==1)
                m=0;
            else if(m==0)
                m=2;
            else
                m=1;
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }
        if(m==0)
            x5+=a[s-1];
        else if(m==1)
            x5+=b[s-1];
        else
            x5+=c[s-1];
        
        
        s=f1,m=2;
        visited=v;
        while(s!=f2)
        {
            if(m==0)
                x6+=a[s-1];
            else if(m==1)
                x6+=b[s-1];
            else
                x6+=c[s-1];
            if(m==2)
                m=1;
            else if(m==1)
                m=0;
            else
                m=2;
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }
        if(m==0)
            x6+=a[s-1];
        else if(m==1)
            x6+=b[s-1];
        else
            x6+=c[s-1];

        if(x1<=x2&&x1<=x3&&x1<=x4&&x1<=x5&&x1<=x6)
        {
            cout<<x1<<endl;
            s=f1;
            m=1;
            visited=v;
            while(s!=f2)
            {
                ans[s]=m;
                if(m==1)
                    m=2;
                else if(m==2)
                    m=3;
                else
                    m=1;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }
            ans[s]=m;
        }
        
        else if(x2<=x1&&x2<=x3&&x2<=x4&&x2<=x5&&x2<=x6)
        {
            cout<<x2<<endl;
            s=f1;
            m=2;
            visited=v;
            while(s!=f2)
            {
                ans[s]=m;
                if(m==2)
                    m=3;
                else if(m==3)
                    m=1;
                else
                    m=2;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }
            ans[s]=m;
        }
        
        else if(x3<=x1&&x3<=x2&&x3<=x4&&x3<=x5&&x3<=x6)
        {
            cout<<x3<<endl;
            s=f1;
            m=3;
            visited=v;
            while(s!=f2)
            {
                ans[s]=m;
                if(m==2)
                    m=3;
                else if(m==3)
                    m=1;
                else
                    m=2;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }
            ans[s]=m;
        }
        
        else if(x4<=x1&&x4<=x2&&x4<=x3&&x4<=x5&&x4<=x6)
        {
            cout<<x4<<endl;
            s=f1;
            m=1;
            visited=v;
            while(s!=f2)
            {
                ans[s]=m;
                if(m==2)
                    m=1;
                else if(m==3)
                    m=2;
                else
                    m=3;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }
            ans[s]=m;
        }
        
        else if(x5<=x1&&x5<=x2&&x5<=x3&&x5<=x4&&x5<=x6)
        {
            cout<<x5<<endl;
            s=f1;
            m=2;
            visited=v;
            while(s!=f2)
            {
                ans[s]=m;
                if(m==2)
                    m=1;
                else if(m==3)
                    m=2;
                else
                    m=3;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }
            ans[s]=m;
        }
        else
        {
            cout<<x6<<endl;
            s=f1;
            m=3;
            visited=v;
            while(s!=f2)
            {
                ans[s]=m;
                if(m==2)
                    m=1;
                else if(m==3)
                    m=2;
                else
                    m=3;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }
            ans[s]=m;
        }
        
        for(i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        exit(0);
    }
    else
    {
        vll visited=v;
        ll s=1;
        ll x1=0,x2=0,x3=0,x4=0,x5=0,x6=0;
        ll m=0;
        do{
            if(m==0){
                x1+=a[s-1];
                m=1;
            }
            else if(m==1)
            {
                x1+=b[s-1];
                m=2;
            }
            else
            {
                x1+=c[s-1];
                m=0;
            }
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }while(s!=1);

        m=1;
        s=1;
        visited=v;
        do{
            if(m==0){
                x2+=a[s-1];
                m=1;
            }
            else if(m==1)
            {
                x2+=b[s-1];
                m=2;
            }
            else
            {
                x2+=c[s-1];
                m=0;
            }
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }while(s!=1);
        
        m=2;
        s=1;
        visited=v;
        do{
            if(m==0){
                x3+=a[s-1];
                m=1;
            }
            else if(m==1)
            {
                x3+=b[s-1];
                m=2;
            }
            else
            {
                x3+=c[s-1];
                m=0;
            }
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }while(s!=1);
        
        m=0;
        s=1;
        visited=v;
        do{
            if(m==0){
                x4+=a[s-1];
                m=2;
            }
            else if(m==1)
            {
                x4+=b[s-1];
                m=0;
            }
            else
            {
                x4+=c[s-1];
                m=1;
            }
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }while(s!=1);
        
        m=1;
        s=1;
        visited=v;
        do{
            if(m==0){
                x5+=a[s-1];
                m=2;
            }
            else if(m==1)
            {
                x5+=b[s-1];
                m=0;
            }
            else
            {
                x5+=c[s-1];
                m=1;
            }
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }while(s!=1);

        m=2;
        s=2;
        visited=v;
        do{
            if(m==0){
                x6+=a[s-1];
                m=2;
            }
            else if(m==1)
            {
                x6+=b[s-1];
                m=0;
            }
            else
            {
                x6+=c[s-1];
                m=1;
            }
            visited[s]=1;
            if(visited[g[s][0]]==0)
                s=g[s][0];
            else
                s=g[s][1];
        }while(s!=1);
        
        if(x1<=x2&&x1<=x3&&x1<=x4&&x1<=x5&&x1<=x6)
        {
            cout<<x1<<endl;
            s=1;
            m=1;
            visited=v;
            do
            {
                ans[s]=m;
                if(m==1)
                    m=2;
                else if(m==2)
                    m=3;
                else
                    m=1;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }while(s!=1);
        }

        else if(x2<=x1&&x2<=x3&&x2<=x4&&x2<=x5&&x2<=x6)
        {
            cout<<x2<<endl;
            s=1;
            m=2;
            visited=v;
            do
            {
                ans[s]=m;
                if(m==2)
                    m=3;
                else if(m==3)
                    m=1;
                else
                    m=2;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }while(s!=1);
        }
        
        else if(x3<=x1&&x3<=x2&&x3<=x4&&x3<=x5&&x3<=x6)
        {
            cout<<x3<<endl;
            s=1;
            m=3;
            visited=v;
            do
            {
                ans[s]=m;
                if(m==2)
                    m=3;
                else if(m==3)
                    m=1;
                else
                    m=2;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }while(s!=1);
        }
        
        else if(x4<=x1&&x4<=x2&&x4<=x3&&x4<=x5&&x4<=x6)
        {
            cout<<x4<<endl;
            s=1;
            m=3;
            visited=v;
            do
            {
                ans[s]=m;
                if(m==2)
                    m=1;
                else if(m==3)
                    m=2;
                else
                    m=3;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }while(s!=1);
        }
        
        else if(x5<=x1&&x5<=x2&&x5<=x3&&x5<=x4&&x5<=x6)
        {
            cout<<x5<<endl;
            s=1;
            m=2;
            visited=v;
            do
            {
                ans[s]=m;
                if(m==2)
                    m=1;
                else if(m==3)
                    m=2;
                else
                    m=3;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }while(s!=1);
        }
        else
        {
            cout<<x6<<endl;
            s=1;
            m=3;
            visited=v;
            do
            {
                ans[s]=m;
                if(m==2)
                    m=1;
                else if(m==3)
                    m=2;
                else
                    m=3;
                visited[s]=1;
                if(visited[g[s][0]]==0)
                    s=g[s][0];
                else
                    s=g[s][1];
            }while(s!=1);
        }
        
        for(i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        exit(0);
    }
    return 0;
}
