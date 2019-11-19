#include<bits/stdc++.h>
#include<set>
using namespace std;
typedef long long ll;
#define pb push_back
#define ull unsigned long long
#define mp make_pair
const int maxn=1e5+5;
const ll inf=1e9+7;
ll mod=1e9+7;
//bool p[maxn][maxn];
int n,m;
//ll ans=0;
//inline void dfs(int x,int y){
//    if(y>m){
//        ans++;
////        for(int i=1;i<=n;i++){
////            for(int j=1;j<=m;j++){
////                cout<<p[i][j]<<" ";
////            }
////            puts("");
////        }
////        puts("-------------");
//        return ;
//    }
//
////    cout<<"x="<<x<<"  y="<<y<<endl;
////
////    for(int i=1;i<=n;i++){
////            for(int j=1;j<=m;j++){
////                cout<<p[i][j]<<" ";
////            }
////            puts("");
////        }
////    puts("*************");
//
//    int ax,ay;
//    if(x>1 && y>1){
//        if(p[x-1][y]&&p[x][y-1]){
//            if(x==n){
//                ax=1,ay=y+1;
//            }
//            else{
//                ax=x+1,ay=y;
//            }
//            for(int i=0;i<1;i++){
//                p[x][y]=i;
//                dfs(ax,ay);
//                p[x][y]=0;
//            }
//        }
//        else if(!p[x-1][y]&&!p[x][y-1]){
//            if(x==n){
//                ax=1,ay=y+1;
//            }
//            else{
//                ax=x+1,ay=y;
//            }
//            for(int i=1;i<2;i++){
//                p[x][y]=i;
//                dfs(ax,ay);
//                p[x][y]=0;
//            }
//        }
//        else{
//            if(x==n){
//                ax=1,ay=y+1;
//            }
//            else{
//                ax=x+1,ay=y;
//            }
//            for(int i=0;i<2;i++){
//                if(p[x-1][y-1]==i)continue;
//                if(x<n&&p[x+1][y-1]==p[x][y-1]&&p[x][y-1]==i)continue;
//                p[x][y]=i;
//                dfs(ax,ay);
//                p[x][y]=0;
//            }
//        }
//    }
//    else if(x==1&&y==1){
//        if(x==n){
//            ax=1,ay=y+1;
//        }
//        else{
//            ax=x+1,ay=y;
//        }
//        for(int i=0;i<2;i++){
//            p[x][y]=i;
//            dfs(ax,ay);
//            p[x][y]=0;
//        }
//    }
//    else if(x==1){
//        if(x==n){
//            ax=1,ay=y+1;
//        }
//        else{
//            ax=x+1,ay=y;
//        }
//        for(int i=0;i<2;i++){
//            if(y>2&&p[x][y-2]==i&&p[x][y-1]==p[x][y-2])continue;
//            if(n>1&&p[x][y-1]==p[x+1][y-1]&&p[x][y-1]==i)continue;
//            p[x][y]=i;
//            dfs(ax,ay);
//            p[x][y]=0;
//        }
//    }
//    else{
//        if(x==n){
//            ax=1,ay=y+1;
//        }
//        else{
//            ax=x+1,ay=y;
//        }
//        for(int i=0;i<2;i++){
//            if(x>2&&p[x-2][y]==i&&p[x-2][y]==p[x-1][y])continue;
//            p[x][y]=i;
//            dfs(ax,ay);
//            p[x][y]=0;
//        }
//    }
//}
ll dp1[maxn];
ll dp2[maxn];
int main(){
    cin>>n>>m;
    dp1[1]=2,dp1[2]=4;
    for(int i=3;i<=m;i++){
        dp1[i]=(dp1[i-1]+dp1[i-2])%mod;
    }
    dp2[1]=0,dp2[2]=2;
    for(int i=3;i<=n;i++){
        dp2[i]=(dp2[i-1]+dp2[i-2])%mod;
    }


    ll ans=dp1[m];
    if(n==2)printf("%I64d\n",(ans+2)%mod);
    else if(n>2){
        for(int i=1;i<=n;i++){
            ans=(ans+dp2[i])%mod;
        }
        printf("%I64d\n",ans%mod);
    }
    else printf("%I64d\n",ans);

//    for(int i=1;i<=30;i++){
//        for(int j=1;j<=5;j++){
//            ans=0;
//            n=i,m=j;
//            dfs(1,1);
//            cout<<"i="<<i<<"  j="<<j<<"  ans="<<ans<<"   ";
//        }
//        puts("");
//    }
    return 0;
}

/*

*/
