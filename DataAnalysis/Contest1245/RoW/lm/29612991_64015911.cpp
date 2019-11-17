using namespace std;



const long long MOD = 1e9+7;

int main()
{
    string s;
    cin >> s;

    vector <int> cnt;
    char last = '?';
    long long ans = 1;

    vector <int> dp(s.size() + 55);
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<dp.size(); ++i)
    {
        dp[i] = (dp[i-1] + dp[i-2])%MOD;
    }

    for (auto c:s)
    {
        if (c == 'n' && last == 'n')
            cnt[cnt.size()-1]++;
        else if (c == 'n')
            cnt.push_back(1), last = c;
        else if (c == 'u' && last == 'u')
            cnt[cnt.size()-1]++;
        else if (c == 'u')
            cnt.push_back(1), last = c;
        else if (c == 'w' || c == 'm')
            ans = 0;
        else
            last = '?';
    }

    if (ans)
    {
        for (auto k:cnt)
        {
            ans *= dp[k];
            ans%=MOD;
        }
    }

    cout << ans;

    return 0;
}
