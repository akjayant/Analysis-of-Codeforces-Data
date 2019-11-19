#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
typedef long long ll;
using namespace std;
const int maxn=5e5+5;
int abit[35],bbit[35],cbit[35];
int n,q;
ll dp[35][3][3];
ll dfs(int dep,bool limit1,bool limit2){
    if(dep==0){
        return 1;
    }
    if(dp[dep][limit1][limit2]!=-1)return dp[dep][limit1][limit2];
    ll ans=0;
    int up1=limit1?abit[dep]:1;
    int up2=limit2?bbit[dep]:1;
    for(int i=0;i<=up1;i++){
        for(int j=0;j<=up2;j++){
            if(i&j)continue;
            ans+=dfs(dep-1,limit1&&i==up1,limit2&&j==up2);
        }
    }
    return dp[dep][limit1][limit2]=ans;
}
ll solve(int a,int b){
    memset(dp,-1,sizeof(dp));
    if(a<0||b<0)return 0;
    for(int i=1;i<=30;i++){
        abit[i]=a&1;
        bbit[i]=b&1;
        a>>=1;
        b>>=1;
    }
    return dfs(30,1,1);
}

int main(){
    int t;
    scanf("%d",&t);
    int a,b,c;
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%lld\n",solve(b,b)-solve(a-1,b)-solve(b,a-1)+solve(a-1,a-1));

    }
    return 0;
}