using namespace std;
long long solve(string s){
    if(s.size()<2) return 1;
    long long dp[s.size()+1];
    for (long long i = 0; i < s.size()+1; ++i)
    {
        dp[i]=1;
    }
    for (long long i = s.size()-2; i >= 0; --i)
    {
        if(s[i]==s[i+1] && s[i]=='n') dp[i]=dp[i+1]+dp[i+2];
        else if(s[i]==s[i+1] && s[i]=='u') dp[i]=dp[i+1]+dp[i+2];
        else dp[i]=dp[i+1];
        dp[i]%=1000000007;
    }
    return dp[0]%1000000007;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    for (long long i = 0; i < s.size(); ++i)
    {
        if(s[i]=='w' || s[i]=='m'){
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<solve(s)%1000000007<<endl;
    return 0;
}
