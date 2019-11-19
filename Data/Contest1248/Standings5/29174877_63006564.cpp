#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//const int maxn=19;
//int a[maxn][maxn];
//int n,m;
//pair<int,int> getid(int x){
//    return make_pair(x/m+1,x%m+1);
//}
//vector<pair<int,int> > v;
//
//bool cc(){
//    for(int i=1;i<=n;++i)
//        for(int j=1;j<=m;++j){
//            if(i+1<=n&&a[i+1][j]==a[i][j]&&j+1<=m&&a[i][j+1]==a[i][j]) return 0;
//            if(i-1>=1&&a[i-1][j]==a[i][j]&&j+1<=m&&a[i][j+1]==a[i][j]) return 0;
//            if(i-1>=1&&a[i-1][j]==a[i][j]&&j-1>=1&&a[i][j-1]==a[i][j]) return 0;
//            if(i+1<=n&&a[i+1][j]==a[i][j]&&j-1>=1&&a[i][j-1]==a[i][j]) return 0;
//            if(i+1<=n&&a[i+1][j]==a[i][j]&&i-1>=1&&a[i-1][j]==a[i][j]) return 0;
//            if(j-1>=1&&a[i][j-1]==a[i][j]&&j+1<=m&&a[i][j+1]==a[i][j]) return 0;
//        }
//    return 1;
//}
//
//bool check(){
//    if(!cc()) return 0;
////    for(int i=0;i<v.size();++i){
////        a[v[i].first][v[i].second]=1;
////        if(cc()) return 0;
////        a[v[i].first][v[i].second]=0;
////    }
//
//    return 1;
//}
//
//int main(){
//    //scanf("%d%d",&n,&m);
//
//    for(n=1;n<=5;++n){
//        for(m=1;m<=5;++m){
//            int res=0;
//            for(int val=0;val<(1<<(n*m));++val){
//                memset(a,0,sizeof(a));
//                v.clear();
//                for(int i=0;i<n*m;++i){
//                    pair<int,int> p=getid(i);
//                    //cout<<p.first<<" "<<p.second<<endl;
//                    if(val&(1<<i)) a[p.first][p.second]=1;
//                    else a[p.first][p.second]=0,v.push_back(p);
//                }
//                if(check()){
////                    for(int i=1;i<=n;++i){
////                        for(int j=1;j<=m;++j) cout<<a[i][j]<<" ";
////                        cout<<endl;
////                    }
////                    cout<<endl;
//                    ++res;
//                }
//            }
//            cout<<res<<" ";
//
//        }
//        cout<<endl;
//    }
//
//    return 0;
//}

const int maxn=1e5+7;
const int mod=1e9+7;
ll a[maxn];
ll sum[maxn];
ll b[maxn];

int main(){
    a[2]=2,a[3]=2;
    sum[2]=2,sum[3]=a[2]+a[3];
    for(int i=4;i<maxn;++i) a[i]=(a[i-1]+a[i-2])%mod,sum[i]=(sum[i-1]+a[i])%mod;
    int n,m;
    scanf("%d%d",&n,&m);
//    if(n==1||m==1){
//        b[1]=1,b[2]=1,b[3]=3,b[4]=3,b[5]=4,b[6]=6,b[7]=9;
//        for(int i=8;i<maxn;++i) b[i]=(b[i-2]+b[i-3]+b[i-4]-b[i-6]+mod)%mod;
//        if(n==1) swap(n,m);
//        printf("%I64d\n",b[n]);
//    }
//    else{
//        printf("%I64d\n",(6+sum[n]+sum[m])%mod);
//    }
    printf("%I64d\n",(2+sum[n]+sum[m])%mod);
    return 0;
}
