#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[40][2][2][2][2];
int abit[33],bbit[33];
ll dfs(int len,int lim1,int lim2,int z1,int z2){
    if(len==-1)return 1;
    if(dp[len][lim1][lim2][z1][z2]!=-1)return dp[len][lim1][lim2][z1][z2];
    ll ans=0;
    int up1=lim1?abit[len]:1;
    int up2=lim2?bbit[len]:1;
    for(int i=0;i<=up1;i++){
        for(int j=0;j<=up2;j++){
            if((i+j)==(i^j)){
                ans+=dfs(len-1,lim1&&i==up1,lim2&&j==up2,z1||i!=0,z2||j!=0);
            }
        }
    }
    dp[len][lim1][lim2][z1][z2]=ans;
    return ans;
}
ll slove(ll a,ll b){
    memset(dp,-1, sizeof(dp));
    for(int i=30;i>=0;i--){
        abit[i]=a>>i&1;
        bbit[i]=b>>i&1;
    }
    dfs(30,1,1,0,0);
}
ll t,l,r;
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    ll a,b,c;
    while (t--){
        cin>>l>>r;
        if(l==0){
            a=slove(r,r);
            cout<<a<<endl;
            continue;
        }
//        cout<<(a=slove(r,r))<<' ';
//        cout<<(b=slove(l-1,l-1))<<' ';
//        cout<<(c=slove(l-1,r))<<' ';
//        cout<<endl;
        a=slove(r,r);
        b=slove(l-1,l-1);
        c=slove(l-1,r);
        cout<<a+b-c-c<<endl;
    }
}