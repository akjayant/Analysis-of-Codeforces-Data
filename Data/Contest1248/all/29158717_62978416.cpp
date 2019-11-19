#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        long long odd_n, even_n, odd_m, even_m;
        odd_n = even_n = odd_m = even_m = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            if (p % 2 == 0)
                even_n++;
            else
                odd_n++;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int q;
            cin >> q;
            if (q % 2 == 0)
                even_m++;
            else
                odd_m++;
        }
        cout << even_n * even_m + odd_n * odd_m << "\n";
    }
    return 0;
}
