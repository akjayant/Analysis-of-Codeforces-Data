#include<bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
#define drap(i,n,s) for(int i=n;i>=s;i--)
using namespace std;
typedef long long ll;
#define N 100100
int n,c[3][N],f[N],d[N],head;
int cx[3][N],ts[N];
bool vis[N];
ll ans=0,temps[3][3];
int nxt[N][2];
int main(){
    scanf("%d",&n);
    rap(k,0,2) rap(i,1,n) scanf("%d",&c[k][i]);
    int x,y;
    rap(i,2,n){
        scanf("%d%d",&x,&y);
        d[x]++; d[y]++; if(d[x]>2||d[y]>2){printf("-1\n"); return 0;}
        nxt[x][d[x]-1]=y; nxt[y][d[y]-1]=x;
    }
    rap(i,1,n) if(d[i]==1){head=i; break;}
    x=head; int fx=0; int q=1; while(x){
        cx[0][q]=c[0][x];
        cx[1][q]=c[1][x];
        cx[2][q]=c[2][x];
        q++;
        if(nxt[x][0]==fx){
            fx=x,x=nxt[x][1];
        }
        else fx=x,x=nxt[x][0];
    }
    ans=1000000000ll*n;
    int fk1=0,fk2=1;
    rap(k1,0,2) rap(k2,0,2) if(k1!=k2){
        temps[k1][k2]=cx[k1][1]+cx[k2][2];
        int f1=k1,f2=k2,f3;
        rap(i,3,n){
            f3=3-f1-f2;
            temps[k1][k2]+=cx[f3][i];
            f1=f2,f2=f3;
        }
        if(ans>temps[k1][k2]) ans=temps[k1][k2],fk1=k1,fk2=k2;
    }
    int fk3=3-fk1-fk2;
    x=head; fx=0;
    ts[x]=fk1;
    if(nxt[x][0]==fx){
        fx=x,x=nxt[x][1];
    }
    else fx=x,x=nxt[x][0];
    ts[x]=fk2;
    if(nxt[x][0]==fx){
        fx=x,x=nxt[x][1];
    }
    else fx=x,x=nxt[x][0];
    
    while(x){
        ts[x]=fk3;
        if(nxt[x][0]==fx){
            fx=x,x=nxt[x][1];
        }
        else fx=x,x=nxt[x][0];
        fk1=fk2,fk2=fk3; fk3=3-fk1-fk2;
    }
    printf("%I64d\n",ans);
    rap(i,1,n) printf("%d ",ts[i]+1);
    return 0;
}