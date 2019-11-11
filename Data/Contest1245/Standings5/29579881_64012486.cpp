#include <bits/stdc++.h>

using namespace std;
#define taskname "cf1245"

int T, a, b;

int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    for (cin >> T; T--;)
    {
        cin >> a >> b;
        a = __gcd(a, b);
        if (a == 1)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
    }
}
