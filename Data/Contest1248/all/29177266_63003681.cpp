#include <cstdio>
#include <algorithm>
#define DIMN 510
#define MOD 1000000007
using namespace std;
long long dp[100010][2][2];
int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;
    int n,m,i;
    long long sol;
    fscanf (fin,"%d%d",&n,&m);
    /// ne prefacem ca incepem mereu cu N
    /// 2 consec negre
    dp[1][1][0] = 1;
    dp[1][0][0] = 1;
    for (i=2;i<=max(n,m);i++){
        dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1])%MOD;
        dp[i][1][1] = dp[i-1][1][0];
        dp[i][0][0] = (dp[i-1][1][0] + dp[i-1][1][1])%MOD;
        dp[i][0][1] = dp[i-1][0][0];
    }
    /// cazurile pt prima linie
    sol = (dp[n][0][0] + dp[n][0][1] + dp[n][1][0] + dp[n][1][1])%MOD;
    /// cazurile cand nu exista repetitii DELOC pe prima linie
    sol -= 2;
    sol += (dp[m][0][0] + dp[m][0][1] + dp[m][1][0] + dp[m][1][1])%MOD;
    fprintf (fout,"%lld",(sol + MOD)%MOD);
    return 0;
}
