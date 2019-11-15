#include <cstdio>
#include <iostream>
#define MOD 1000000007
using namespace std;
char s[100010];
int dp[100010];
int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int n,st;
    char c;
    c=fgetc(fin);
    n = 0;
    dp[0] = 1;
    st = 1;
    while (c!='\n'){
        n++;
        s[n] = c;
        if (s[n] == 'm' || s[n] == 'w')
            st = 0;
        if (n>1 && s[n-1] == s[n]){
            if (s[n] == 'u' || s[n] == 'n')
                dp[n] = (dp[n-1] + dp[n-2])%MOD;
            else dp[n] = dp[n-1];

        }
        else dp[n] = dp[n-1];
        c=fgetc(fin);
    }
    fprintf(fout,"%d",dp[n]*st);
    return 0;
}
