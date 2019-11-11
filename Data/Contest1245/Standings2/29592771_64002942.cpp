#include <bits/stdc++.h>

using namespace std;

int t, n, r, p, s, R, P, S, target, x;
string bob;

void afis(char c)
{
    cout << c;
    if(c == 'P') p--;
    else if(c == 'R') r--;
    else if(c == 'S') s--;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n; target = n/2; if(n%2==1) target++;
        cin >> r >> p >> s;
        cin >> bob;
        R = P = S = 0;
        for(auto it : bob)
            if(it == 'R')
                R++;
            else if (it == 'P')
                P++;
            else if (it == 'S')
                S++;
        x = min(r, S) + min(p, R) + min(s, P);
        if(x < target) cout << "NO\n";
        else
        {
            cout << "YES\n";
            for(auto it : bob)
            {
                if(it == 'R' && p > 0)
                    afis('P');
                else if(it == 'P' && s > 0)
                    afis('S');
                else if(it == 'S' && r > 0)
                    afis('R');
                else
                {
                    if(p > R)
                        afis('P');
                    else if(s > P)
                        afis('S');
                    else if(r > S)
                        afis('R');
                    else if(p >= s && p >= r)
                        afis('P');
                    else if(s >= p && s >= r)
                        afis('S');
                    else if(r >= s && r >= p)
                        afis('R');
                }

                if(it == 'R') R--;
                else if(it == 'P') P--;
                else S--;
            }
            cout << '\n';
        }
    }
    return 0;
}
