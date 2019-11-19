#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rint register int
typedef long long ll;
typedef long long unsigned llu;
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int bs=31;
const double eps=1e-8;
const ll zzz=1e9;
struct iiios{
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template<typename _Tp> inline ios&operator>>(_Tp&x){
        static char ch,sgn;ch=gc(),sgn=0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc()) x=x*10+(ch^'0');
        sgn&&(x=-x);
    }
}io;
int vis[N];
map<int,int>mp[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        mp[u][v]=1;
        mp[v][u]=1;
    }
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            vector<int>vec;
            queue<int>q;
            for(int j=1;j<=n;j++)
                if(j!=i)
                {
                    if (mp[i].count(j))
                        vec.push_back(j);
                    else q.push(j);
                }
            while(q.size())
            {
                int now=q.front();
                q.pop();
                vis[now]=1;
                for(int j=0;j<vec.size();j++)
                {
                    if(!mp[now].count(vec[j]))
                    {
                        q.push(vec[j]);
                        swap(vec[j],vec[vec.size()-1]);
                        vec.pop_back();
                        j--;
                    }
                }
            }
            c++;
        }
    }
    cout<<c-1<<endl;
}
