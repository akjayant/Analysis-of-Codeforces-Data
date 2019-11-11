#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX_N=1e5+5;
const ll M=1e9+7;

int n;
char s[MAX_N+1];
ll f[MAX_N+1];

int main(){
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)if(s[i]=='m'||s[i]=='w'){
        printf("0\n");return 0;
    }
    f[1]=1;f[2]=2;
    for(int i=3;i<=1e5;i++)f[i]=(f[i-1]+f[i-2])%M;
    ll res=1,ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='n')ans++;
        else{
            if(ans)res=res*f[ans]%M;
            ans=0;
        }
    }
    if(ans)res=res*f[ans]%M;
    ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='u')ans++;
        else{
            if(ans)res=res*f[ans]%M;
            ans=0;
        }
    }
    if(ans)res=res*f[ans]%M;
    printf("%I64d\n",res);
    return 0;
}