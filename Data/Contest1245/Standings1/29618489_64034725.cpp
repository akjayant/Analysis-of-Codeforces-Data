
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <ctime>
#include <map>
#define ll long long
using namespace std;
const int maxn=33;
ll dp[maxn][2][2];
ll d1[maxn],d2[maxn];
ll dfs(int pos,int lim1,int lim2){
    if(pos==-1) return 1;
    //if(!lim1&&!lim2&&dp[pos]!=-1) return dp[pos];
    if(dp[pos][lim1][lim2]!=-1) return dp[pos][lim1][lim2]; 
    int up1=lim1?d1[pos]:1;
    int up2=lim2?d2[pos]:1;
    ll ans=0;
    for(int i=0;i<=up1;i++){
        for(int j=0;j<=up2;j++){
            if(!i||!j){
                ans+=dfs(pos-1,lim1&&i==up1,lim2&&j==up2);
            }
        }
    }
    dp[pos][lim1][lim2]=ans;
    //if(!lim1&&!lim2) dp[pos]=ans;
    return ans;
}
ll solve(int n,int m){
    for(int i=0;i<33;i++) dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=-1,d1[i]=d2[i]=0;
    int p1=-1,p2=-1;
    while(n){
        d1[++p1]=n%2;
        n/=2;
    }
    while(m){
        d2[++p2]=m%2;
        m/=2;
    }
    return dfs(max(p1,p2),1,1);
}
int main(){
    ios::sync_with_stdio(false);
    int T,l,r;
    cin>>T;
    while(T--){
        cin>>l>>r;
        ll ans=0;
        ans+=solve(r,r);
        ans-=2*solve(l-1,r);
        ans+=solve(l-1,l-1);
        cout<<ans<<endl; 
    }
	return 0;
}