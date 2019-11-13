#include <bits/stdc++.h>

using namespace std;

int k, n;
string s, t;
vector <int> ara;

int main()
{
  	iostream::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    for (int p = 0 ; p < k ; p++)
    {
        cin >> n >> s >> t;
        ara.clear();
        for (int i = 0 ; i < n ; i++)
        {
            if (s[i] != t[i])
                ara.push_back(i);
        }
        if (ara.size() == 2)
        {
            if (s[ara[0]] == s[ara[1]] && t[ara[1]] == t[ara[0]])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else if (ara.size() == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
