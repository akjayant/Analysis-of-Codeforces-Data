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

    int64_t n;

    std::cin >> n;

    int64_t ans = n;

    for(int64_t i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }

            if(n == 1)
            {
                ans = i;
                break;
            }
            else
            {
                ans = 1;
                break;
            }
        }
    }

    std::cout << ans;

    return 0;
}
