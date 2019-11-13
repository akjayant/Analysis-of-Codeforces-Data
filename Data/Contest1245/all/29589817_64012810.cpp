#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vpii         vector<pair<int,int>>
#define gph          map<int, vector<int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define FORS(i, n) for(; i < (int)(n); i++)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define printArr(A,n) { cout << #A << " = "; FOR(i,n) cout << A[i] << ' '; cout << endl; }
using namespace std;
#define int long long int

#define mod (int)1e9 + 7
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    string s;cin >> s;
    vector<int> dp(s.length() + 1);
    dp[0] = 1;
    bool done = false;
    FOR1(i, s.length()){
       int ind = i-1;

       if(s[ind] == 'm')dp[i] = 0, done = true;
       else if(s[ind] == 'w')dp[i] = 0, done = true;
       else if(ind > 0 && s[ind] == s[ind-1] && s[ind-1] == 'u'){
           dp[i] = dp[i-2] + dp[i-1];
       }else if(ind > 0 && s[ind] == s[ind-1] && s[ind-1] == 'n'){
           dp[i] = dp[i-2] + dp[i-1];
       }else{
            dp[i] = dp[i-1];
       }
       dp[i] %= mod;
    }
    if(done)cout << 0<<endl;
    else cout << dp[s.length()]<<endl;
}


