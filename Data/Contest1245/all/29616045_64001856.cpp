#include<bits/stdc++.h>

using namespace std;


int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;  cin >> t;

    while (t--) {
        int n;  cin >> n;
        int r;  cin >> r;
        int p;  cin >> p;
        int s;  cin >> s;

        string S;   cin >> S;
        string T;   T.assign(n,'0');

        int ans = 0;

        for(int i = 0 ; i < n ; ++i)    {
            if (S[i] == 'R' && p)   --p, ++ans, T[i] = 'P';
            if (S[i] == 'P' && s)   --s, ++ans, T[i] = 'S';
            if (S[i] == 'S' && r)   --r, ++ans, T[i] = 'R';
        }

        if (ans >= (n + 1) / 2) {
            cout << "YES\n";
            for(int i = 0 ; i < n ; ++i)    if (T[i] == '0')    {
                if (p)  {   --p;    T[i] = 'P'; continue;   }
                if (s)  {   --s;    T[i] = 'S'; continue;   }
                if (r)  {   --r;    T[i] = 'R'; continue;   }
            }
            cout << T << "\n";
        }
        else
            cout << "NO\n";
    }
}