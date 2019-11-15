#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


string s;
ll dp[100100];
ll md = 1e9 +7;

int main()
{
    cin >> s;
    if (s.find('m') != s.npos) return puts("0");
    if (s.find('w') != s.npos) return puts("0");
    dp[s.size()] = 1;
    for (int i = s.size() - 1 ; i >= 0; --i)
    {
        if (s[i] == 'u' || s[i] == 'n')
        {
            dp[i] = dp[i+1] ;
            if (s[i] == s[i+1])
                dp[i] += dp[i+2];
            if (dp[i] >= md)
                dp[i] -= md;
        }
        else dp[i] = dp[i+1];
    }
    cout << dp[0] << "\n";

    return 0;

}
