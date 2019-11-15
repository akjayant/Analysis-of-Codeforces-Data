#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

char str[100005];
ll dp[100005][2];

ll func(int n)
{
    assert(n>1);
    int i;
    dp[0][0]=1;
    dp[0][1]=0;
    for(i=1; i<n; i++) {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=dp[i-1][0];
    }
    ll ans=(dp[n-1][0]+dp[n-1][1])%MOD;

    return ans;
}

int main(int argc, char* argv[])
{
    scanf("%s", str);
    int n=strlen(str);

    ll ans=1;
    int cnt=0;
    int i;
    for(i=0; i<n; i++) {
        if(str[i]=='m' || str[i]=='w') {
            printf("0\n"); return 0;
        }
        if(str[i]=='u' || str[i]=='n') {
            if(i>0 && str[i-1]==str[i]) {
                cnt++;
            }
            else {
                if(cnt>1) {
                    ans = (ans * func(cnt)) %MOD;
                }
                cnt=1;
            }
        }
        else {
            if(cnt>1) ans = (ans * func(cnt)) %MOD;
            cnt=0;
        }
    }
    if(cnt>1) {
        ans = (ans * func(cnt)) %MOD;
    }
    printf("%lld\n", ans);

    return 0;
}

