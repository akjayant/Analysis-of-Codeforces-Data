#include <bits\stdc++.h>
using namespace std;
int n, m, k, t;
string s;
void Read()
{
    cin >> n >> s;
}
void slove()
{
    int pos = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            pos = max(pos, max(i + 1, n - i));
    if (pos)
        cout << 2 * pos << '\n';
    else
        cout << n << '\n';
}
int main()
{
    cin >> t;
    while (t--) {
        Read();
        slove();
    }
}