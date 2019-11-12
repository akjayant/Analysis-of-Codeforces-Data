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

        std::string a, b;
        std::cin >> a >> b;

        std::vector<size_t> neq_index;
        for(size_t j = 0; j < n; ++j)
        {
            if(a[j] != b[j])
            {
                neq_index.push_back(j);
            }
        }

        if(neq_index.empty() || (neq_index.size() == 2 && (a[neq_index[0]] == a[neq_index[1]] && b[neq_index[0]] == b[neq_index[1]])))
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
