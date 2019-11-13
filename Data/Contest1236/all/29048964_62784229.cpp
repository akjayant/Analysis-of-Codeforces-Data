#include <bits/stdc++.h>
#define endl "\n"
#define INF (int)1e9
#define ll long long
#define ull unsigned long long

using namespace std;

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int ans = 0;

        int first = min(b, c / 2);
        ans += 3 * first;
        b -= first;

        int second = min(a, b / 2);
        ans += 3 * second;

        cout << ans << endl;
    }
}