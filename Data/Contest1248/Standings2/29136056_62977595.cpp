#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

#define llg     long long

int main()
{
    std::ios_base::sync_with_stdio(false);

    llg T;  input >> T;
    while (T--) {
        llg N;  input >> N;
        llg odd = 0, even = 0;
        for (llg i=0, x; i<N; ++i) {
            input >> x;
            if (x&1) odd++;
            else     even++;
        }

        llg M;  input >> M;
        llg odd2 = 0, even2 = 0;
        for (llg i=0, x; i<M; ++i) {
            input >> x;
            if (x&1) odd2++;
            else     even2++;
        }

        output << (odd*odd2 + even*even2) << '\n';
    }

    return 0;
}
