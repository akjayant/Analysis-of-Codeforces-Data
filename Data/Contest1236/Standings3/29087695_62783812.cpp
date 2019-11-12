#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int answer = 0;
        int take = min (b, c / 2);
        answer += take * 3;
        b -= take;
        take = min (a, b / 2);
        answer += take * 3;
        cout << answer << '\n';
    }

    return 0;
}
