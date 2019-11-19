/***********************************************
 *                   _ooOoo_                   *
 *                  o8888888o                  *
 *                  88" . "88                  *
 *                  (| -_- |)                  *
 *                  O\  =  /O                  *
 *               ____/`---'\____               *
 *             .'  \\|     |//  `.             *
 *            /  \\|||  :  |||//  \            *
 *           /  _||||| -:- |||||-  \           *
 *           |   | \\\  -   * |    |           *
 *           | \_|  ''\---/''  |   |           *
 *           \  .-\__  `-`  ___/-. /           *
 *         ___`. .'  /--.--\  `. . __          *
 *      ."" '<  `.___\_<|>_/___.'  >'"".       *
 *     | | :  `- \`.;`\ _ /`;.`/ - ` : | |     *
 *     \  \ `-.   \_ __\ /__ _/   .-` /  /     *
 *======`-.____`-.___\_____/___.-`____.-'======*
 *                   `=---='                   *
 *^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

             佛祖保佑       永无BUG

   本程序已经经过开光处理，绝无可能再产生bug
 **********************************************/
#include<algorithm>
#include <iostream>
#include  <cstdlib>
#include  <cstring>
#include   <string>
#include   <vector>
#include   <cstdio>
#include    <queue>
#include    <stack>
#include    <ctime>
#include    <cmath>
#include      <map>
#include      <set>
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
#define mkp(a,b) make_pair(a,b)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define db1(x) cout<<#x<<"="<<(x)<<endl
#define db2(x,y) cout<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<endl
#define db3(x,y,z) cout<<#x<<"="<<(x)<<", "<<#y<<"="<<(y)<<", "<<#z<<"="<<(z)<<endl
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[(1<<22)],*p1=buf,*p2=buf;
inline ll read(){
    char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
const int maxn=2005;
struct Edge{
    int u,v;ll w;
    bool operator < (const Edge &E)const{
        return w < E.w;
    }
};
vector<Edge>edges;
ll X[maxn],Y[maxn],C[maxn],K[maxn];
ll dist(int i,int j){
    return abs(X[i]-X[j])+abs(Y[i]-Y[j]);
}
int n,p[maxn];
vector<int>idx;
vector<pii>ans;
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
ll krus(){
    sort(edges.begin(),edges.end());
    for(int i=0;i<=n;i++)p[i]=i;ll ret=0;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int fu=find(u);
        int fv=find(v);
        if(fu!=fv){
            if(u==0)idx.push_back(v);
            else if(v==0)idx.push_back(u);
            else{
                ans.push_back(mkp(u,v));
            }
            p[fu]=fv;ret+=edges[i].w;
        }
    }
    return ret;
}
int main(){
    #ifdef DanDan
    freopen("in.txt","r",stdin);
    //freopen("in.txt","w",stdout);
    clock_t start=clock();
    #endif //DanDan
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&X[i],&Y[i]);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&C[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&K[i]);
    for(int i=1;i<=n;i++){
        edges.push_back({0,i,C[i]});
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edges.push_back({i,j,dist(i,j)*(K[i]+K[j])});
        }
    }
    printf("%lld\n",krus());
    printf("%d\n",(int)idx.size());
    for(int i=0;i<idx.size();i++){
        printf(i==idx.size()-1?"%d\n":"%d ",idx[i]);
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    #ifdef DanDan
    clockid_t end=clock();
    double endtime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n\n\n\n\n");
    cout<<"Total time:"<<endtime<<"s"<<endl;        //s为单位
    cout<<"Total time:"<<endtime*1000<<"ms"<<endl;    //ms为单位
    #endif //DanDan
    return 0;
}


// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ????━????   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

