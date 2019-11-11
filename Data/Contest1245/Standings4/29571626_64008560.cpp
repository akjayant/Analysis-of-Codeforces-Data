#include <bits/stdc++.h>
using namespace std;
long long dp[100001];

long long ansi(int curr){
    if(curr == 0){
        return 1;
    }
    if(curr == -1){
        return 0;
    }
    if(dp[curr] != -1){
        return dp[curr];
    }
    long long ret = ansi(curr-2)+ansi(curr-1);
    return dp[curr] = ret%1000000007;
}

int main(){
    memset(dp , -1 , sizeof dp);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0 ; i < n ; i += 1){
        if(s[i] == 'w' || s[i] == 'm'){
            cout << 0;
            return 0;
        }
    }
    vector<int> vals;
    for(int i = 0 ; i < n ; i += 1){
        if(s[i] == 'u'){
            int j = i;
            while(i < n-1 && s[i+1] == 'u'){
                i += 1;
            }
            vals.push_back(i-j+1);
        }
        if(s[i] == 'n'){
            int j = i;
            while(i < n-1 && s[i+1] == 'n'){
                i += 1;
            }
            vals.push_back(i-j+1);
        }
    }
    long long ans = 1;
    for(int i : vals){
        ans *= ansi(i);
        ans %= 1000000007;
    }
    cout << ans;
}