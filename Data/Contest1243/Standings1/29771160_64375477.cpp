#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <array>
#include <string>
#include <queue>
#include <random>
#include <memory>

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t k;

    std::cin >> k;

    for(size_t i = 0; i < k; ++i)
    {
        size_t n;
        std::cin >> n;
        std::vector<size_t> a(n);
        for(size_t j = 0; j < n; ++j)
        {
            std::cin >> a[j];
        }
        std::sort(a.begin(), a.end());
        std::reverse(a.begin(), a.end());

        size_t max_len;
        for(max_len = 0; max_len < a.size() && a[max_len] >= max_len + 1; ++max_len);

        std::cout << max_len << "\n";
    }

    return 0;
}
