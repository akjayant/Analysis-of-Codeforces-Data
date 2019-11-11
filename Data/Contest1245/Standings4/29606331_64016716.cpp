#include <iostream>

int64_t R[100005];
const int64_t mod = 1000000007;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::string s;
    std::cin >> s;
    int64_t r = 0;
    R[0] = 1;
    for (char c : s) if (c == 'm' || c == 'w') R[0] = 0;
    for (int i=1;i<=s.length();++i)
    {
        R[i] = (R[i]+R[i-1]) % mod;
        if (i>1 && s[i-2] == 'u' && s[i-1] == 'u')   R[i] = (R[i]+R[i-2]) % mod;
        if (i>1 && s[i-2] == 'n' && s[i-1] == 'n')   R[i] = (R[i]+R[i-2]) % mod;
    }
    std::cout << R[s.length()];
    return 0;
}