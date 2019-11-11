#pragma GCC optimize("O3")
#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)
ll N;
char S[101010];
ll dp[101010];
ll i,j,k;
int main(){
    scanf("%s", &S);
    N = strlen(S);
    dp[0] = 1;
    fornum(i,0,N){
        if((S[i]=='u'&&S[i+1]=='u')||
            (S[i]=='n'&&S[i+1]=='n')){
            dp[i+2]=(dp[i]+dp[i+2])%MOD;
        }else if(S[i]=='m'||S[i]=='w'){
            printf("0");
            return 0;
        }
        dp[i+1]=(dp[i]+dp[i+1])%MOD;
        
    }
    printf("%lld", dp[N]);

    return 0;
}