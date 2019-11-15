#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nt;
    cin >> nt;
    while (nt--)
    {
        int n, r, p, s;
        cin >> n >> r >> p >> s;

        int win_cnt = 0;
        string bob, answer;
        cin >> bob;

        for (int i = 0; i < n; i++)
            answer += " ";
        for (int i = 0; i < n; i++)
            if (bob[i] == 'R' && p > 0)
                win_cnt++, p--, answer[i] = 'P';
            else if (bob[i] == 'P' && s > 0)
                win_cnt++, s--, answer[i] = 'S';
            else if (bob[i] == 'S' && r > 0)
                win_cnt++, r--, answer[i] = 'R';
        if (win_cnt * 2 >= n)
        {
            for (int i = 0; i < n; i++)
                if (answer[i] == ' ')
                    if (r > 0)
                        r--, answer[i] = 'R';
                    else if (p > 0)
                        p--, answer[i] = 'P';
                    else if (s > 0)
                        s--, answer[i] = 'S';
            cout << "YES" << endl << answer << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
