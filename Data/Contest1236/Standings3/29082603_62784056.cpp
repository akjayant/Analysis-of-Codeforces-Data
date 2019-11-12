#include<bits/stdc++.h>
using namespace std;
const int MX = (1<<20);
int dp[102][102][102];
int calc(int a , int b , int c){
    int &ret = dp[a][b][c]; if(ret != -1) return ret;
    ret = 0;
    if(a > 0 && b > 1) ret = max(ret , calc(a - 1 , b - 2 , c) + 3);
    if(b > 0 && c > 1) ret = max(ret , calc(a , b - 1 , c - 2) + 3);
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("exptree.in","r",stdin);
#endif
    memset(dp , -1 , sizeof(dp));
    int T;
    cin>>T;
    while(T--){
        int a , b , c;
        cin>>a>>b>>c;
        cout<<calc(a , b , c)<<endl;
    }
}