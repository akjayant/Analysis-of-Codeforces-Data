#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
string s;
vector<int> v;
ll dp[100005][2];//第i位是不是合并的
ll ans[100005];
int main(){
    ios::sync_with_stdio(false);
    cin>>s;
    int n = s.length();
    for(int i=0,j;i<n;i=j+1){
        j=i;
        if(s[i]=='u'){
            int cnt=0;
            while (j<n&&s[j]=='u')j++,cnt++;
            j--;
            if(cnt>1)v.push_back(cnt);
        }
        if(s[i]=='n'){
            int cnt=0;
            while (j<n&&s[j]=='n')j++,cnt++;
            j--;
            if(cnt>1)v.push_back(cnt);
        }
        if(s[i]=='w'||s[i]=='m'){
            cout<<0<<endl;
            exit(0);
        }
    }
    dp[1][0]=1;//不合并
    dp[1][1]=0;//合并
    for(int i=2;i<=100000;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][0]%=mod;
        dp[i][1]%=mod;
    }
    for(int i=1;i<=100000;i++)ans[i]=(dp[i][0]+dp[i][1])%mod;
    ll ed=1;
    for(auto x:v){
//        cout<<x<<endl;
        ed = ed*ans[x]%mod;
    }
    cout<<ed<<endl;
}