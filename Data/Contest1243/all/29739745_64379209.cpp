#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    string a, b;
    int    n, m, l;
    cin >> n;
    while (n--)
    {
        set<char> p, q;
        l = 0;
        cin >> m >> a >> b;
        if (a == b)
        {
            cout << "YES\n"; continue;
        }
        for (int i = 0; i < m; i++)
        {
            if (a[i] != b[i])
                l++, p.insert(a[i]), q.insert(b[i]);
        }
        if (p.size() == 1 && q.size() == 1 && l == 2)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}
