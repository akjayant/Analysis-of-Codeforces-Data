#include<bits/stdc++.h>
using namespace std;

#define fi(i,a,b)    for(int i=a;i<=b;i++)
#define fr(i,a)      for(int i=0;i<a;i++)
#define fd(i,a,b)    for(int i=b;i>=a;i--)
#define clr(x)       memset(x,0,sizeof(x))
#define cln(x)       memset(x,-1,sizeof(x))
#define __           printf(" ")
#define _            printf("\n")
#define _o           printf("1\n")
#define stree        long long lft=node<<1,rht=(node<<1)|1,mid=(s+e)>>1
#define snode        long long s,long long e,long long node
#define slft         s,mid,lft
#define srht         mid+1,e,rht
#define sin()        if(S<=s&&e<=E)
#define sout()       if(S>e||s>E)
#define mod          1000000007
#define read()       freopen("in.txt","r",stdin)
#define write()      freopen("out.txt","w",stdout)
#define sfl(x)       scanf("%I64d",&x)
#define sfll(x,y)    scanf("%I64d %I64d",&x,&y)
#define sflll(x,y,z) scanf("%I64d %I64d %I64d",&x,&y,&z)
#define pfl(x)       printf("%I64d",x)
#define pfll(x,y)    printf("%I64d %I64d",x,y)
#define pflll(x,y,z) printf("%I64d %I64d %I64d",x,y,z)
#define xx           100000

typedef long long ll;
typedef pair<long long,long long> pll;


vector<int>vec[xx+10];

int c[4][xx+10];
int cnt[xx+10];
int st;
int u,v;
int x[xx+10];


long long dfs(long long cur,long long pre,long long a,long long b){
    int sz=vec[cur].size();
    long long ret;
    int col;
    fi(i,1,3) if(i!=a&&i!=b) col=i;
    ret=(long long)c[a][cur];
    x[cur]=a;
    fr(i,sz) if(vec[cur][i]!=pre) ret+=dfs(vec[cur][i],cur,col,a);
    return ret;
}






main(){
    int n;

    cin>>n;
    fi(i,1,3) fi(j,1,n) scanf("%d",&c[i][j]);

    fi(i,2,n){
       scanf("%d %d",&u,&v);
       vec[u].push_back(v);
       vec[v].push_back(u);
       cnt[u]++;
       cnt[v]++;
    }

    long long ans=-1;
    fi(i,1,n) if(cnt[i]>2) {
       cout<<ans<<endl;
       return 0;
    }
    else if(cnt[i]==1) u=i;
    v=vec[u][0];



    int a,b;

    fi(i,1,3) fi(j,1,3) if(i!=j){
        long long cur=(long long)c[i][u]+dfs(v,u,j,i);
        if(ans==-1||ans>cur){
            ans=cur;
            a=i;
            b=j;
        }
    }

    x[u]=a;

    dfs(v,u,b,a);

    //cout<<u<<" "<<v<<endl;

    cout<<ans<<endl;
    fi(i,1,n){
       printf("%d",x[i]);
       if(i==n) _;
       else __;
    }



    return 0;
}
