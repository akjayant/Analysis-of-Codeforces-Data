#include<bits/stdc++.h>
using  namespace std;

typedef  pair<int,int> pii;
char s[(int)1e5+5];
const long long mod=1e9+7;
long long  F[(int)1e5+5];
vector<int> v;
int main(){
    scanf("%s",&s);
    int cnt=0,n=strlen(s),ma=1;
    s[n]='a';
    for(int i=0;i<=n;i++){
        if(s[i]=='w' or s[i]=='m') return !printf("0");
        if(s[i]=='n') cnt++;
        else{
            if(cnt>1) v.push_back(cnt);
            if(cnt > ma) ma=cnt;
            cnt=0;
        }
    }
    cnt=0;
    for(int i=0;i<=n;i++){
        if(s[i]=='u') cnt++;
        else{
            if(cnt > 1) v.push_back(cnt);
            if(cnt > ma) ma=cnt;
            cnt=0;
        }
    }
    if(v.empty()) return !printf("1");
    F[0]=1,F[1]=1;
    for(int i=2;i<=ma;i++){
        F[i]=F[i-1]+F[i-2];
        F[i]%=mod;
    }
    long long ans=1;
    for(auto it:v){
        ans *= F[it];
        ans%=mod;
    }
    printf("%lld",ans);



}
