/*   Author : Rshs
 *   Data : 2019-11-01-23.10
 */
#include<bits/stdc++.h>
using namespace std;
#define FI first
#define SE second
#define LL long long
#define MP make_pair
#define PII pair<int,int>
#define SZ(a) (int)a.size()
const double pai = acos(-1);
const double eps = 1e-10;
const LL mod = 1e9+7;
const int MXN = 1e6+5;
char s[MXN];
LL dp[MXN];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    dp[1]=1;dp[0]=1;
    for(int i=1;i<=n;i++) if(s[i]=='m'||s[i]=='w')
        return puts("0"),0;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1];
        if(s[i]=='u'&&s[i-1]=='u') dp[i]+=dp[i-2],dp[i]%=mod;
        if(s[i]=='n'&&s[i-1]=='n') dp[i]+=dp[i-2],dp[i]%=mod;
    }
    cout<<dp[n]<<'\n';
    return 0;
}
