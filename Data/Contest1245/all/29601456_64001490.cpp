#include<bits/stdc++.h>
using namespace std;
#define mx 100009
#define mod 1000000007

int dp[mx];
char str[mx];
int n;
int func(int ind) {
    if(ind>=n)
        return 1;
    int &ret = dp[ind];
    if(~ret)
        return ret;
    ret = 0;
    if(str[ind]=='m' || str[ind]=='w')
        return ret;
    ret = func(ind+1);
    if(str[ind]==str[ind+1] && (str[ind]=='u' || str[ind]=='n')){
        ret += func(ind+2);
        if(ret>=mod) ret -= mod;
    }
    return ret;
}
int main()
{
    scanf("%s",str);
    n = strlen(str);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",func(0));
    return 0;
}
