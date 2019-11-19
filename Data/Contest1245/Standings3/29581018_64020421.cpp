#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10;

struct node{
    int x,y;
    long long cost;
};

int n;
node e[maxn*maxn+10];
int mark[maxn*maxn+10]={0};
int nn;
int p[maxn],r[maxn];
int c[maxn],k[maxn];
int x[maxn],y[maxn];
long long kq;

bool cmp(node x,node y){
    return x.cost<y.cost;
}

int find(int i){
    while(p[i]!=-1) i=p[i];
    return i;
}

void join(int i,int j){
    int tmp=r[i]+r[j];
    if (r[i]>r[j]){
        r[i]=tmp;p[j]=i;
    }
    else{
        r[j]=tmp;p[i]=j;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>k[i];
    nn=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            nn++;e[nn].x=i;e[nn].y=j;
            e[nn].cost=1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
        }
    for(int i=1;i<=n;i++){
        nn++;
        e[nn].x=n+1;e[nn].y=i;e[nn].cost=c[i];
    }
    sort(e+1,e+nn+1,cmp);
    kq=0;
    for(int i=1;i<=n+1;i++) p[i]=-1;
    for(int i=1;i<=n+1;i++) r[i]=1;
    for(int i=1;i<=nn;i++){
        int ii=find(e[i].x);
        int jj=find(e[i].y);
        if (ii!=jj){
            kq=kq+e[i].cost;
            mark[i]=1;
            join(ii,jj);
        }
    }
//    for(int i=1;i<=nn;i++) cout<<"("<<e[i].x<<" "<<e[i].y<<" "<<e[i].cost<<" "<<mark[i]<<")";cout<<endl;
    cout<<kq<<endl;
    int cnt=0;
    for(int i=1;i<=nn;i++)
        if (e[i].x==n+1 && mark[i]==1) cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=nn;i++)
        if (e[i].x==n+1 && mark[i]==1) cout<<e[i].y<<" ";cout<<endl;
    cout<<n-cnt<<endl;
    for(int i=1;i<=nn;i++)
        if (mark[i]==1 && e[i].x!=n+1) cout<<e[i].x<<" "<<e[i].y<<endl;
}
