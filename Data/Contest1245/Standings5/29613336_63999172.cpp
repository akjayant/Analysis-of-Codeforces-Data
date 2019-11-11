#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <iomanip>

using namespace std;


int main() {
    int n, m, t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        cin >> n >> m;
        if (n == 1 || m == 1)
        {
            cout << "Finite" << endl;
            continue;
        }
        int p = 0;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                if (m % i == 0 || m % (n / i) == 0)
                {
                    cout << "Infinite" << endl;
                    p = 1;
                    break;
                }
            }
        }
        if (p == 0 && m % n != 0)
            cout << "Finite" << endl;
        else if (p == 0)
            cout << "Infinite" << endl;
    }
    
}
