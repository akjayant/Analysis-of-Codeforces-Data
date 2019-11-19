#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    int t;
    std::cin >> t;
    for (int tt=0;tt<t;++tt)
    {
        int n,m;
        int64_t c[4] = {0, 0, 0, 0};
        std::cin >> n;
        for (int i=0;i<n;++i)
        {
            int q;
            std::cin >> q;
            c[q%2]++;
        }
        std::cin >> m;
        for (int i=0;i<m;++i)
        {
            int q;
            std::cin >> q;
            c[q%2+2]++;
        }
        std::cout << c[0]*c[2] + c[1]*c[3] << "\n";
    }
    return 0;
}