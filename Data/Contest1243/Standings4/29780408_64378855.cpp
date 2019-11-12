#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n, idx1=-1, idx2=-1, cnt = 0;
        cin >> n;
        string s, t;
        cin >> s >> t;
        for (int i=0; i<n; ++i)
        {
            if (s[i] == t[i])
                continue;
            idx2 = idx1;
            idx1 = i;
            ++cnt;
        }
        if (cnt == 0 || (cnt == 2 && s[idx1] == s[idx2] && t[idx2] == t[idx1]))
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }

    return 0;
}









