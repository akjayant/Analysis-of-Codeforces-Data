#include <bits/stdc++.h>
using namespace std;

#define maxn 10010

int ntest, n;
string s, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> ntest;
    for (int test = 1; test <= ntest; test++)
    {
        cin >> n;
        cin >> s;
        cin >> t;
        vector<int> dif;
        dif.clear();
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]) dif.push_back(i);
        if (dif.size() != 2) cout << "No";
        else
        {
            int id1 = dif[0];
            int id2 = dif[1];
            if (s[id1] == s[id2] && t[id1] == t[id2]) cout << "Yes";
            else cout << "No";
        }
        cout << endl;
    }
    return 0;
}
