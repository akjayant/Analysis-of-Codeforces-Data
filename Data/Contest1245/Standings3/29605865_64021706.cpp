#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct Q{
    long long x,y,c,k;
}A[4010];
struct P{
    int a,b;
    long long c;
}B[4000010];
int cmp(P a,P b){
    return a.c<b.c;
}


int cnt=0,p[4010],vis[4010];
int f(int a){
    if(p[a]==a) return a;
    p[a]=f(p[a]);
    return p[a];
}


int l[4000010],r[4000010],ans[4010];
int main(){
    int i,j,n;
    cin>>n;
    for(i=1;i<=n;i++) cin>>A[i].x>>A[i].y;
    for(i=1;i<=n;i++) cin>>A[i].c;
    for(i=1;i<=n;i++) cin>>A[i].k;

    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
           B[++cnt].a=i;
           B[cnt].b=j;
           B[cnt].c=abs(A[i].x-A[j].x)+abs(A[i].y-A[j].y);
           B[cnt].c*=A[i].k+A[j].k;
        }
        B[++cnt].a=i;
        B[cnt].b=i;
        B[cnt].c=A[i].c;
    }
    sort(B+1,B+1+cnt,cmp);
    for(i=1;i<=n;i++) p[i]=i;

    int c,d,x=0,y=0;
    long long sum=0;
    for(i=1;i<=cnt;i++){
        if(B[i].a==B[i].b){
             c=f(B[i].a);
             if(vis[c]==0){
                  ans[++x]=B[i].a;
                  sum+=B[i].c;
                  vis[c]=1;
             }
        }
        else{
            c=f(B[i].a);
            d=f(B[i].b);
            if(vis[c]&&vis[d]) continue;

            if(c!=d){
                 p[c]=d;
                 vis[d]|=vis[c];
                 sum+=B[i].c;
                 l[++y]=B[i].a;
                 r[y]=B[i].b;
            }
        }
    }

    cout<<sum<<endl;
    cout<<x<<endl;
    for(i=1;i<=x;i++) cout<<ans[i]<<" ";
    cout<<endl;
    cout<<y<<endl;
    for(i=1;i<=y;i++) cout<<l[i]<<" "<<r[i]<<endl;
    return 0;
}


