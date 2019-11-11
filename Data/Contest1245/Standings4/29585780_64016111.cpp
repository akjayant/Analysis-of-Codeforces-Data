#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+50;

ll F[maxn];
char s[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    F[0]=F[1]=1;
    for(int i=2;i<maxn;++i) F[i]=(F[i-1]+F[i-2])%mod;
    scanf("%s",s);
    int len=strlen(s);
    bool ok=true;
    ll ans=1LL;
    for(int i=0;i<len;){
        if(s[i]=='w' || s[i]=='m'){
            ok=false;
            break;
        }
        if(s[i]=='n' || s[i]=='u'){
            int j=i;
            while(j<len && s[j]==s[i]) ++j;
            ans=(ans*F[j-i])%mod;
            i=j;
        }
        else ++i;
    }
    if(!ok) puts("0");
    else printf("%I64d\n",ans);
    return 0;
}