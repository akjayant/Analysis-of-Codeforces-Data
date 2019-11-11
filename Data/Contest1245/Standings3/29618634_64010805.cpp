#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
const int mod=1e9+7;
ll dp[maxn];
char a[maxn];
int main() {
    scanf("%s",&a);
    int n=strlen(a);
    int flag=0;
    for(int i=0;i<n;i++){
        if(a[i]=='m'||a[i]=='w')flag=1;
    }
    if(flag==1) {
            printf("0\n");
            return 0;
    }
    dp[0]=1;
    for(int i=1;i<n;i++){
        if(a[i]=='n'&&i>=1&&a[i-1]=='n'){
           if(i-2<0) {
             dp[i]=(1+dp[i-1])%mod;
           }else{
            dp[i]=(dp[i-2]+dp[i-1])%mod;
           }

        }
        else if(a[i]=='u'&&i>=1&&a[i-1]=='u'){
            if(i-2<0) {
             dp[i]=(1+dp[i-1])%mod;
           }else{
            dp[i]=(dp[i-2]+dp[i-1])%mod;
           }
        }else dp[i]=dp[i-1];
    }
    printf("%lld\n",dp[n-1]);
    return 0;
}
