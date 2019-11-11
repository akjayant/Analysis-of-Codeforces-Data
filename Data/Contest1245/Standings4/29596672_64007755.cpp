#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define num     int
#define llg     long long

#define MOD     1000000007

#define MAXN    100005

llg DP[MAXN];

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::string str;
    input >> str;

    DP[1] = 1;
    DP[2] = 2;
    for (int i=3; i<=str.size(); ++i)
        DP[i] = (DP[i-1] + DP[i-2])%MOD;

    llg ans = 1;
    for (int i=0; i<str.size(); ++i) {
        if (str[i] == 'u' || str[i] == 'n') {
            char ch = str[i];
            int idx = i;
            llg len = 1;
            while (idx+1 < str.size() && str[idx+1] == ch) ++ idx, ++ len;
            ans = (ans*DP[len])%MOD;
            i = idx;
        }   else
        if (str[i] == 'w' || str[i] == 'm') ans = 0;

    }   output << ans << '\n';

    return 0;
}
