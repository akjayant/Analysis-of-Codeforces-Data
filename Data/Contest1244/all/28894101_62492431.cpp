#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss second
#define ff first
using namespace std;
typedef pair<ll,ll> pii;
int br,stek[100010],niz[5],rniz[5],n,pp[100010];
ll c[5][100010],maxx;
vector<int>vect[100010];
void go(int x,int prv){
    stek[++br]=x;
    for(int i=0;i<vect[x].size();i++){
        int id=vect[x][i];
        if(id==prv)continue;
        go(id,x);
    }
}
void check(){
   ll rez1=0;
   ///printf("%d %d %d CHECK\n",niz[1],niz[2],niz[3]);
    for(int i=1;i<=br;i++){
        int id=stek[i];
        if(i%3==1)rez1+=c[niz[1]][id];
        else if(i%3==2)rez1+=c[niz[2]][id];
        else if(i%3==0)rez1+=c[niz[3]][id];
    }
    ///printf("%lld %lld  EHEH\n",rez1,maxx);
    if(rez1<maxx){
        maxx=rez1;
        rniz[1]=niz[1];
        rniz[2]=niz[2];
        rniz[3]=niz[3];
    }
}
int main(){

    //freopen("test.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&c[1][i]);
    for(int i=1;i<=n;i++)scanf("%lld",&c[2][i]);
    for(int i=1;i<=n;i++)scanf("%lld",&c[3][i]);
    maxx=1e18;

    for(int i=1;i<n;i++){
       int u,v;
       scanf("%d %d",&u,&v);
       vect[u].pb(v);
       vect[v].pb(u);
    }

    int id=0;
    for(int i=1;i<=n;i++)
       if(vect[i].size()>2){
        printf("-1\n");
        return 0;
       }
       else if(vect[i].size()==1)id=i;

    go(id,0);

    niz[1]=1;
    niz[2]=2;
    niz[3]=3;

    check();
    while(next_permutation(niz+1,niz+4))check();

    printf("%lld\n",maxx);
    for(int i=1;i<=br;i++){
        int id=stek[i];
        if(i%3==1)pp[id]=rniz[1];
        else if(i%3==2)pp[id]=rniz[2];
        else if(i%3==0)pp[id]=rniz[3];
    }
    for(int i=1;i<=n;i++)printf("%d ",pp[i]);
    printf("\n");

    return 0;
}
