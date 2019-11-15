#include <bits/stdc++.h>
#define loop(i, a, b) for(long long  i=a;i<b;i++)
#define mn 500100
#define mod 1000000007
 
using namespace std;
 
typedef long long ll;

ll euc(ll a, ll b){
    if(a%b==0) return b;
    return euc(b, a%b);
}

int main() {
    string s;cin >> s;s+='/';
    ll tu=0, tn=0, ans=1;
    loop(i, 0, s.length()){
        if(s.at(i)=='w' or s.at(i)=='m' ){
            cout << "0"<<endl;
            return 0;
        }
    }
    loop(i, 0,s.length()){
        if(s.at(i)=='u') tu++;
        if(i>0 and s.at(i)!=s.at(i-1) and s.at(i-1)=='u'){
            vector<ll> dp(tu+1);dp[0]=1;
            loop(j, 1, tu+1){
                dp[j]=dp[j-1];
                if(j>1) dp[j]+=dp[j-2];
                dp[j]%=mod;
            }
            ans*=dp[tu];ans%=mod;
            tu =0;
        }
        if(s.at(i)=='n') tn++;
        if(i>0 and s.at(i)!=s.at(i-1) and s.at(i-1)=='n'){
            vector<ll> dp(tn+1);dp[0]=1;
            loop(j, 1, tn+1){
                dp[j]=dp[j-1];
                if(j>1) dp[j]+=dp[j-2];
                dp[j]%=mod;
            }
            ans*=dp[tn];ans%=mod;
            tn =0;
        }
    }
    cout << ans<<endl;
}