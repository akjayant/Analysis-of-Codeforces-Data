#include <bits/stdc++.h>
#define F(i,j,k) for(int i=(j);i<=(k);++i)
#define D(i,j,k) for(int i=(j);i>=(k);--i)
#define rep(it,s) for(auto it=s.begin();it!=s.end();++it)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO{
    template <class T>
    inline void read(T &x){
        x=0;int f=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
        while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
    }
};
using namespace IO;
const int N=1e5+5;
vector<int>E[N];
int n,m,fa[N],degree[N],top,num,flag[N],nest[N],indx;
inline void add(int x,int y){
    E[x].PB(y),E[y].PB(x);
    ++degree[x],++degree[y];
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void uni(int x,int y){
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
int main(){
    //freopen("txt.in","r",stdin);freopen("txt.out","w",stdout);
    read(n),read(m);num=n;
    int tu,tv;
    F(i,1,m){
        read(tu),read(tv);
        add(tu,tv);
    }
    F(i,1,n)fa[i]=i;
    F(i,1,n){
        if(degree[i]<(n+1)/2){
            if(!top)top=i;
            else uni(i,top),--num;
        }
        else nest[++indx]=i;
    }
    F(i,1,indx){
        int x=nest[i];
        rep(it,E[x])flag[*it]=1;
        F(j,1,n)if(!flag[j]&&x!=j){
            if(find(x)!=find(j))uni(x,j),--num;
        }
        rep(it,E[x])flag[*it]=0;
    }
    printf("%d\n",num-1);
    return 0;
}