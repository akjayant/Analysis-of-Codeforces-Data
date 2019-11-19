#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, i, res = 0, cnt = 0;
    cin >> n;
    long long a = n;
    for (long long i = 2; i <= (round(sqrt(n))); i++)
        if (a % i == 0){
            if (cnt == 0)
                res = i;
            while (a % i == 0)
                a /= i;
            cnt++;
            if (cnt == 2)
                break;
        }
    if (cnt == 0)
        cout << n;
    else if (cnt == 1 && a == 1)
        cout << res;
    else
        cout << 1;
    return 0;
}
