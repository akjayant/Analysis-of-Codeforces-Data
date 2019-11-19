#include <iostream>
#include <algorithm>

int64_t M[100001];

const int64_t mod = 1000000007;

void solve(int n)
{
    M[1] = 2;
    M[2] = 4;
    for (int i=3;i<n;++i)
        M[i] = (M[i-1] + M[i-2]) % mod;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n, m;
    solve(100001);
    std::cin >> n >> m;
    std::cout << (M[n]+M[m]-2+mod) % mod << std::endl;
    return 0;
}