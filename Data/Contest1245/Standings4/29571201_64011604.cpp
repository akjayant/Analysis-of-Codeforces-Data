#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const long long P = 1e9 + 7;
const int N = 100010;
long long dp[N];
char s[N];
int main()
{
    int n;
    long long ans = 1;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    dp[1] = dp[0] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % P;
    for (int i = 1; i <= n; ++i){
        if (s[i] == 'm' || s[i] == 'w'){
            printf("0");
            return 0;
        } else if (s[i] == 'n' || s[i] == 'u'){
            int cnt = 1;
            while(s[i + cnt] == s[i]) cnt++;
            ans = ans * dp[cnt] % P;
            i = i + cnt - 1;
        }
    }
    printf("%lld", ans);
    // system("pause");
}