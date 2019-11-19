#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        char a[1010];

        int ans = 0;
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            if (a[i] == '1')
                flag = true;
        }

        if (!flag)
            std::cout << n << "\n";
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (a[i] == '1')
                {
                    int cur = std::max(i + 1, n - i) + std::max(i + 1, n - i);
                    ans = std::max(ans, cur);
                }
            }

            std::cout << ans << "\n";
        }
    }
}
