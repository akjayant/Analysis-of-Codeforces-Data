//{Headers
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<string>
#include<algorithm>
#include<list>
#include<queue>
#include<deque>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<bitset>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair< int,int > pii;
#define mp(x,y) make_pair(x,y)
typedef long long ll;
//}

const int MAXN=1e5,MOD=1e9+7;
ll dp[MAXN];

int main(void){
//    freopen("in.txt","r",stdin);
    int N,M;
    while(~scanf("%d%d",&N,&M)){
        dp[0]=dp[1]=1;
        for(int i=2,up=max(N,M);i<=up;i++)
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        printf("%I64d\n",((dp[N]*2-1)%MOD+(dp[M]*2-1)%MOD)%MOD);
    }
    return 0;
}

/*
2 3

4
*/
