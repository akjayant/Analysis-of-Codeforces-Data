#include <iostream>
#include <algorithm>
#include <cstring>

int B[256];

int main()
{
    std::ios_base::sync_with_stdio(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        int n,a,b,c;
        std::string bob, alice;
        std::cin >> n >> a >> b >> c >> bob;
        memset(B, 0, 256*sizeof(int));
        for (char c : bob) ++B[c];
        int wins = std::min(a, B['S']) + std::min(b, B['R']) + std::min(c, B['P']);
        if (wins < (n+1)/2) std::cout << "NO\n";
        else
        {
            std::cout << "YES\n";
            for (char x : bob)
            {
                if (x=='S' && a > 0) { --a; alice += 'R'; }
                else if (x=='R' && b > 0) { --b; alice += 'P'; }
                else if (x=='P' && c > 0) { --c; alice += 'S'; }
                else alice += '?';
            }
            for (char& x : alice)
            {
                if (x != '?') continue;
                if (a > 0) { --a; x = 'R'; }
                else if (b > 0) { --b; x = 'P'; }
                else if (c > 0) { --c; x = 'S'; }
            }
            std::cout << alice << "\n";
        }
    }
    return 0;
}