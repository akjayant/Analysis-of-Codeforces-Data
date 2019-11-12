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

        std::vector<std::array<size_t, 2>> answer;
        bool banswer = true;

        for(size_t pos = 0; pos < n; ++pos)
        {
            bool ok = false;

            for(size_t j = pos + 1; j < n; ++j)
            {
                if(a[pos] == a[j])
                {
                    answer.push_back({j, pos});
                    std::swap(a[j], b[pos]);
                    ok = true;
                    break;
                }
            }

            if(!ok)
            {
                for(size_t j = pos; j < n; ++j)
                {
                    if(a[pos] == b[j])
                    {
                        if(pos != j)
                        {
                            answer.push_back({n - 1, j});
                            std::swap(a[n - 1], b[j]);
                            answer.push_back({n - 1, pos});
                            std::swap(a[n - 1], b[pos]);
                        }
                        ok = true;
                        break;
                    }
                }
            }

            if(!ok)
            {
                banswer = false;
                break;
            }
        }

        if(banswer)
        {
            std::cout << "Yes\n" << answer.size() << "\n";
            for(size_t j = 0; j < answer.size(); ++j)
            {
                std::cout << (answer[j][0] + 1) << " " << (answer[j][1] + 1) << "\n";
            }
        }
        else
        {
            std::cout << "No\n";
        }
    }

    return 0;
}
