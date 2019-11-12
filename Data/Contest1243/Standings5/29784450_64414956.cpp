#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> a(26, 0);
        for (int i = 0; i < n; i++)
        {
            a[s[i] - 'a'] += 1;
            a[t[i] - 'a'] += 1;
        }
        bool flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] % 2 != 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "No" << endl;
            continue;
        }
        else
        {
            vector<pair<int, int>> ans;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != t[i])
                {
                    int check = 0, pos = -1;
                    for (int j = i + 1; j < n; j++)
                    {
                        if (s[i] == s[j])
                        {
                            check = 1;
                            pos = j;
                            break;
                        }
                    }
                    if (check == 1)
                    {
                        char temp = t[i];
                        t[i] = s[pos];
                        s[pos] = temp;
                        ans.push_back(make_pair(pos + 1, i + 1));
                    }
                    else
                    {
                        for (int j = i + 1; j < n; j++)
                        {
                            if (s[i] == t[j])
                            {
                                pos = j;
                                break;
                            }
                        }
                        char temp = s[pos];
                        s[pos] = t[pos];
                        t[pos] = temp;
                        ans.push_back(make_pair(pos + 1, pos + 1));

                        temp = t[i];
                        t[i] = s[pos];
                        s[pos] = temp;
                        ans.push_back(make_pair(pos + 1, i + 1));
                    }
                }
            }
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}