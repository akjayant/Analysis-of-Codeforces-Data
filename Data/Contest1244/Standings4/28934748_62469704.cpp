#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int minim = n + 1, maxim = -1;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
            {
                minim = min(minim, i);
                maxim = max(maxim, i);
            }

        int rez = n;
        if (minim != n + 1)
            rez = max(n, (maxim + 1) * 2);
        if (maxim != -1)
            rez = max(rez, (n - minim) * 2);

        cout << rez << "\n";
    }


    return 0;
}