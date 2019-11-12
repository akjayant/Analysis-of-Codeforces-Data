#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        string s;
        string t;
        cin >> s;
        cin >> t;
        vector<char> v;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                v.push_back(s[i]);
                v.push_back(t[i]);
            }
        }
        if(v.size() > 4 || v.size() == 2)
            cout << "No\n";
        else if(v.size() == 0)
            cout << "Yes\n";
        else
        {
            if(v[0] == v[2] && v[1] == v[3])
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
