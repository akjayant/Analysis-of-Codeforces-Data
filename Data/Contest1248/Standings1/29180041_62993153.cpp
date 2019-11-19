#include <iostream>
#include <algorithm>
using namespace std;

inline int min(int a, int b) {return a < b ? a : b;}

int cnt(string s)
{
    int n = s.length(), a[n] = {0};
    for (int i = 0; i < n - 1; ++i)
        a[i+1] = a[i] + (s[i] == '(' ? 1 : -1);
    int m = 0;
    for (int i = 0; i < n; ++i)
        m = min(m, a[i]);
    return count(a, a + n, m);
}

int main()
{
    int n, best = -1, rl, rr;
    cin >> n;
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '(') - count(s.begin(), s.end(), ')'))
    {
        cout << "0\n1 1";
        return 0;
    }
    for (int l = 0; l < n; ++l)
    {
        for (int r = 0; r < n; ++r)
        {
            swap(s[l], s[r]);
            int u = cnt(s);
            if (u > best)
                best = u, rl = l, rr = r;
            swap(s[l], s[r]);
        }
    }
    cout << best << '\n' << rl + 1 << ' ' << rr + 1;
    return 0;
}
