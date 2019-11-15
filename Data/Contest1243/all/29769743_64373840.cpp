#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

int main()
{
    std::ios_base::sync_with_stdio(false);

    int K;  input >> K;
    while (K--) {
        int N;  input >> N;
        std::vector <int> V(N);
        for (auto &it:V) input >> it;
        std::sort(V.begin(), V.end());

        int ans = 0;
        for (int i=V.size()-1; i>=0; --i) {
            int x = V.size()-i;
            ans = std::max(ans, std::min(x, V[i]));
        }   output << ans << '\n';
    }

    return 0;
}
