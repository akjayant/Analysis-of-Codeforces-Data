#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define Fi first
#define Se second
#define ll long long
#define inf 0x3f3f3f3f
#define lowbit(x) (x&-x)
#define ull unsigned long long
#define mmin(a,b,c) min(a,min(b,c))
#define mmax(a,b,c) max(a,max(b,c))
#define debug(a) cout<<#a<<"="<<a<<endl;
#define debug2(a,b) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<endl;
#define debug3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<endl;
#define show_time cout<<"The run time is:"<<(double)clock()/CLOCKS_PER_SEC<<"s"<<endl;
using namespace std;
const int N=3e5+10;
struct Node
{
    int  u,v;
    ll c;
};
bool cmp(Node a,Node b)
{
    return a.c<b.c;
}
int f[N];
int find_fa(int rt)
{
    if(f[rt]==rt) return rt;
    return f[rt]=find_fa(f[rt]);
}
vector<Node > vc;
ll c[N],k[N],x[N],y[N];
vector<Node> ans1,ans2;
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&k[i]);
    for(int i=1;i<=n;i++)
    {
        vc.push_back(Node{0,i,c[i]});
        for(int j=i+1;j<=n;j++)
        {
            ll dx=abs(x[i]-x[j])+abs(y[i]-y[j]);
            vc.push_back(Node{i,j,dx*(k[i]+k[j])});
        }
    }
    sort(vc.begin(),vc.end(),cmp);
    for(int i=1;i<=n;i++) f[i]=i;
    ll ans=0;
    for(int i=0;i<vc.size();i++)
    {
        int fu=find_fa(vc[i].u),fv=find_fa(vc[i].v);
        if(fu==fv) continue;
        if(fu!=fv)
        {
            if(vc[i].u==0)
            ans1.push_back(vc[i]);
            else ans2.push_back(vc[i]);
            f[fu]=fv;
            ans+=vc[i].c;
        }
    }
    printf("%lld\n%d\n",ans,ans1.size());
    for(int i=0;i<ans1.size();i++)
    {
        printf("%d ",ans1[i].v);
    }
    printf("\n%d\n",ans2.size());
    for(int i=0;i<ans2.size();i++)
    {
        printf("%d %d\n",ans2[i].u,ans2[i].v);
    }
    return 0;
}
/*
2*3=6+12+2
*/
