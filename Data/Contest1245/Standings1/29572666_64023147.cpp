#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,v,e,x[2010],y[2010],c[2010],k[2010],fa[2010],rt[2010];
ll s;
struct T{
    int x,y;
    ll z;
}a[4000001];
bool operator< (T a,T b){
    return a.z<b.z;
}
int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;++i)scanf("%d",&c[i]);
    for(int i=1;i<=n;++i)scanf("%d",&k[i]);
    for(int i=1;i<n;++i)
        for(int j=i+1;j<=n;++j)
            a[++m]=T{i,j,1LL*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
    for(int i=1;i<=n;++i)a[++m]=T{i,n+1,c[i]};
    sort(a+1,a+m+1);
    for(int i=1;i<=n+1;++i)fa[i]=i;
    for(int i=1;i<=m;++i){
        int X=fnd(a[i].x),Y=fnd(a[i].y);
        if(X==Y)continue;
        if(a[i].x>n||a[i].y>n)rt[++v]=min(a[i].x,a[i].y);
        else ++e,x[e]=a[i].x,y[e]=a[i].y;
        s+=a[i].z;
        fa[X]=Y;
    }
    cout<<s<<endl<<v<<endl;
    for(int i=1;i<=v;++i)cout<<rt[i]<<' ';
    cout<<endl<<e<<endl;
    for(int i=1;i<=e;++i)cout<<x[i]<<' '<<y[i]<<endl;
}