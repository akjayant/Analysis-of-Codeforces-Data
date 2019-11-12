#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define MAXN    305

#define llg     long long

int N;
std::vector <int> ans[MAXN];

int main()
{
    std::ios_base::sync_with_stdio(false);

    input >> N;
    int idx = 1;
    while (idx <= N*N) {
        for (int i=1; i<=N; ++i)
            ans[i].push_back(idx++);
        if (idx > N*N) break;
        for (int i=N; i>=1; --i)
            ans[i].push_back(idx++);
    }
    for (int i=1; i<=N; ++i, output << '\n')
        for (auto &it:ans[i])
            output << it << ' ';

    return 0;
}
