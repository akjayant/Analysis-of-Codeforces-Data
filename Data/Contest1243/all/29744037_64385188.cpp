#include <bits/stdc++.h>

using namespace std;

long long n, cop, i, ok, ans;

int main()
{
    cin >> n;
    cop = n;
    for(i=2; i<=sqrt(cop); i++)
    {
        if(cop % i == 0)
        {
            if (ok == 1)
            {
                cout << 1;
                return 0;
            }
            else
            {
                ok = 1;
                ans = i;
                while(cop%i == 0)
                    cop /= i;
            }
        }
    }
    if(cop != 1 && ok == 1)
    {
        cout << 1;
        return 0;
    }
    if(!ans) ans = n;
    cout << ans;
    return 0;
}
