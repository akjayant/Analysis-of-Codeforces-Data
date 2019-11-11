#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    long long e=1e9+7,fib[s.size()],cnt=1,ans=1;
    fib[0]=1;
    fib[1]=2;
    for(int i=2;i<s.size();i++){
        fib[i]=(fib[i-1]+fib[i-2])%e;
    }
    if(s[0]=='w'||s[0]=='m'){
        cout<<0;
        return 0;
    }
    for(int i=1;i<s.size();i++){
        if(s[i]=='w'||s[i]=='m'){
            cout<<0;
            return 0;
        }
        if(s[i]==s[i-1])
            cnt++;
        else{
            if(s[i-1]=='u'||s[i-1]=='n'){
                ans=(ans*fib[cnt-1])%e;
            }
            cnt=1;
        }
    }
    ans=(ans*fib[cnt-1])%e;
    cout<<ans;
    return 0;
}