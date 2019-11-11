#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
ll fib[mn];
int main(){
    fib[0]=fib[1]=1;
    for(int i=2;i<mn;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
    string s;
    cin>>s;
    int n=s.size();
    ll ans=1;
    int num=1;
    for(char c:s)if(c=='w'||c=='m'){
        printf("0");
        return 0;
    }
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])num++;
        else{
            if(s[i-1]=='u'||s[i-1]=='n'){
                ans=(ans*fib[num])%mod;
            }
            num=1;
        }
    }
    if(s[n-1]=='u'||s[n-1]=='n')ans=(ans*fib[num])%mod;
    printf("%lld",ans);
}