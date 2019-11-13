#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int MOD=1e9+7;
char str[MAXN];
long long fac[MAXN];
void init(){
    fac[1]=1;
    fac[2]=2;
    fac[3]=3;
    for(int i=4;i<MAXN;i++)fac[i]=(fac[i-1]+fac[i-2])%MOD;
}
int main(){
    init();
    scanf("%s",str+1);
    int n=strlen(str+1);
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(str[i]=='m'||str[i]=='w'){
            flag=false;
            break;
        }
    }
    if(!flag)return 0*puts("0");
    long long res=1;
    int idx=1;
    while(idx<=n){
        if(str[idx]=='u'){
            long long cnt=0;
            while(idx<=n&&str[idx]=='u'){
                ++idx;
                ++cnt;
            }
            res=res*fac[cnt]%MOD;
        }else ++idx;
    }
    idx=1;
    while(idx<=n){
        if(str[idx]=='n'){
            long long cnt=0;
            while(idx<=n&&str[idx]=='n'){
                ++idx;
                ++cnt;
            }
            res=res*fac[cnt]%MOD;
        }else ++idx;
    }
    printf("%lld\n",res);
    return 0;
}
