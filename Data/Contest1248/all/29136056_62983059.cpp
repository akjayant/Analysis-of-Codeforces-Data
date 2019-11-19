#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define llg     long long

int main()
{
    std::ios_base::sync_with_stdio(false);

    // x^2 + y^2 maxim
    // sume din v[i]
    // (S-x)^2 + x^2
    // S^2 + 2*x^2 - 2S*x maxim
    // 2*x^2 - 2S*x maxim
    // x^2 - S*x maxim

    int N;  input >> N;
    std::vector <int> V(N);
    for (auto &it:V)
        input >> it;
    std::sort(V.begin(), V.end());
    int ptr1 = 0;
    int ptr2 = V.size()-1;
    int l1 = 0, l2 = 0;
    while (ptr1 <= ptr2) {
        l2 += V[ptr2--];
        if (ptr1 > ptr2) break;
        l1 += V[ptr1++];
    }

    llg x = l1, y = l2;
    output << x*x + y*y << '\n';

    return 0;
}
