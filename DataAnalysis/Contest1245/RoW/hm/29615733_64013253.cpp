using namespace std;
long long dp[5005000], mod = 1e9 + 7, ans = 1;;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[1] = 1;
    dp[2] = 2;
    cin>>s;
    for(int i = 3;i<=s.size();i++) {
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
    for(int i = 0;i<s.size();i++) {
        if(s[i] == 'm' || s[i] == 'w') return cout<<0, 0;
        if(s[i] == 'n' || s[i] == 'u') {
            char curr = s[i];
            int temp = 0;
            while(s[i] == curr) {
                temp++;
                i++;
            }
            i--;
            ans *= dp[temp];
            ans %= mod;
        }
    }
    cout<<ans;
}
