#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1e5 + 7;
const int Mod = 1e9 + 7;
char str[maxn];
int dp[maxn];
int main()
{
    scanf("%s", str+1);
    int n = strlen(str+1);
    dp[0] = dp[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(str[i] == 'w' || str[i] == 'm')
        {
            puts("0");
            return 0;
        }

    }
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1];
        if((str[i] == 'u' || str[i] == 'n') && str[i] == str[i-1]) dp[i] = (dp[i] + dp[i-2])%Mod;
    }
    printf("%d\n", dp[n]);
    return 0;
}
