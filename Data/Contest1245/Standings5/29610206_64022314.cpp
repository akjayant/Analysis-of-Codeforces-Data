/**
* Author : Xiuchen
* Date : 2019-11-01-22.31.05
* Description : 597 Div2 A
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=1e5+10;
char s[maxn];
ll a[maxn];
int main(){
    scanf("%s",s+1);
    a[1]=1;a[2]=2;
    for(int i=3;i<maxn;i++) a[i]=(a[i-1]+a[i-2])%mod;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        if(s[i]=='m'||s[i]=='w'){
            printf("%d\n",0);
            return 0;
        }
    }
    ll ans=1,cnt=0;
    for(int i=1;i<=len;i++){
        if(s[i-1]=='u'&&s[i]!='u'){
            ans=(ans*a[cnt])%mod;
            //printf("%lld %lld %lld\n",cnt,a[cnt],a[2]);
            cnt=0;
        }
        if(s[i]=='u') cnt++;
    }
    if(cnt) ans=(ans*a[cnt])%mod;
    cnt=0;
    for(int i=1;i<=len;i++){
        if(s[i-1]=='n'&&s[i]!='n'){
            ans=(ans*a[cnt])%mod;
            cnt=0;
        }
        if(s[i]=='n') cnt++;
    }
    if(cnt) ans=(ans*a[cnt])%mod;
    cnt=0;
    printf("%lld\n",ans);
    return 0;
}
