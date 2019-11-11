#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s;
int cnt[3];
int t[3];
int to[300];
char output[300];

int main()
{
    int T;
    cin >> T;

    t[0] = 'R';
    t[1] = 'P';
    t[2] = 'S';

    to['R'] = 1;
    to['P'] = 2;
    to['S'] = 0;

    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i<3; i++)
            cin >> cnt[i];

        cin >> s;

        int ans = 0;
        for (int i = 0; i<n; i++)
            if (cnt[ to[ s[i] ] ])
            {
                cnt[ to[ s[i] ]] --;
                ans ++;
                output[ i ] = t[ to[ s[i] ] ];
            }else
                output[i] = 0;

        for (int i = 0, j = 0; i<n; i++)
            if (output[i]==0)
            {
                while (cnt[j]==0)
                    j++;
                
                output[i] = t[j];
                cnt[j] --;
            }

        output[n] = '\0';

        if (ans >= (n+1)/2)
        {
            cout << "YES" << endl;
            cout << string(output) << endl;
        }else
            cout << "NO" << endl;
    }
}