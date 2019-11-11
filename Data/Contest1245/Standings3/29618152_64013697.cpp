#include <iostream>
#include <string>
using namespace std;
const int MAXN=100010;
const int MOD=1e9+7;
 
long long dp[MAXN];
string inp;
int main(){
    ios::sync_with_stdio(false);
 
    cin>>inp;
    inp=' '+inp;
    for(int i=0;i<inp.size();i++){
        if(inp[i]=='m' || inp[i]=='w'){
            cout<<0<<endl;
            return 0;
        }
    }
    dp[0]=1;
    for(int i=1;i<inp.size();i++){
        dp[i]=(dp[i]+dp[i-1])%MOD;
        if(i>=2 && inp[i]==inp[i-1] && (inp[i]=='u' || inp[i]=='n'))dp[i]=(dp[i]+dp[i-2])%MOD;
    }
    cout<<dp[inp.size()-1]%MOD<<endl;
 
    return 0;
}