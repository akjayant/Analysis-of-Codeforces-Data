#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define mod 1000000007

int main(){
    vector<long long > dp(100001,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<100001;i++){
        dp[i]=(dp[i-2]+dp[i-1])%mod;
    }
    string s;
    cin>>s;
    vector<int> v;
    char pr='a';
    for(int i=0;i<s.size();i++){
        if(s[i]=='m'||s[i]=='w'){
            cout<<0;return 0;
        }
        if(pr==s[i]&&(s[i]=='u'||s[i]=='n')){
            v[v.size()-1]++;
        }else if(s[i]=='u'||s[i]=='n')v.push_back(1);
        pr=s[i];
    }
    long long ans=1;
    for(int x:v){
        ans=(ans*dp[x])%mod;
    }
    cout<<ans;
}