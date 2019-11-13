#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

int main()
{
    std::ios_base::sync_with_stdio(false);

    int T;  input >> T;
    int A, B, C;
    while (T--) {
        input >> A >> B >> C;
        int v = std::min(A, B/2);
        int max = 0;
        for (int i=0; i<=v; ++i) {
            int a = A-i;
            int b = B-2*i;
            max = std::max(max, i*3 + std::min(C/2, b)*3);
        }   output << max << '\n';
    }

    return 0;
}
