#include <bits/stdc++.h>

using namespace std;
#define ll long long


ll mod=(ll)1e9+7;

vector<ll> dp(1e5+2,0);
vector<int> dlin(0);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='w' || s[i] == 'm'){
            cout<<0;
            return 0;
        }
    }
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<dp.size();i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mod;
    }

    int len=0;
    char last='0';
    list<pair<char, int>> list1;
    list1.push_back({s[0], 1});
    for(int i=1;i<s.size();i++){
        if(s[i]==list1.back().first){
            list1.back().second++;
        }
        else{
            list1.push_back({s[i], 1});
        }
    }
    ll ans=1;
    for(auto &son:list1){
        if(son.first=='u'){
            ans*=dp[son.second];
            ans%=mod;
        }
        else if(son.first=='n'){
            ans*=dp[son.second];
            ans%=mod;
        }
    }
    cout<<ans;



}