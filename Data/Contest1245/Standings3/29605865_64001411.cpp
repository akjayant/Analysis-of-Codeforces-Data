#include<iostream>
using namespace std;
long long dp[100010],mo=1e9+7;
int main(){
    string s;
    cin>>s;
    int i;
    for(i=0;i<s.size();i++) {
        if(s[i]=='m'||s[i]=='w'){
            cout<<0<<endl;
            return 0;
        }
    }

    dp[0]=1;
    for(i=1;i<=100003;i++){
        if(i-2>=0) dp[i]+=dp[i-2];
        dp[i]+=dp[i-1];
        dp[i]%=mo;
    }
   // cout<<dp[3]<<endl;

    long long ans=1,sum=0;
    s+='#';
    sum=1;
    for(i=0;i<s.size()-1;i++){
        if(s[i]!=s[i+1]){
            if(s[i]=='u'||s[i]=='n') ans*=dp[sum];
            sum=1;
        }
        else sum++;
        ans%=mo;
    }
    cout<<ans<<endl;
    return 0;
}


