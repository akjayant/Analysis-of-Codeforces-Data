#include <iostream>
#include <algorithm>

int L[100000];

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n;
    std::cin >> n;
    for (int i=0;i<n;++i) std::cin >> L[i];
    std::sort(L, L+n);
    int64_t x = 0, y = 0;
    for (int i=0;i<n/2;++i) y += L[i];
    for (int i=n/2;i<n;++i) x += L[i];
    std::cout << x*x + y*y;
    return 0;
}