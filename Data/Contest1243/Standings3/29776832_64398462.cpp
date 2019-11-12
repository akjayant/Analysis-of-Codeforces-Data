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
        vector<pair<int, int> > ans;
        string s;
        string t;
        cin >> s;
        cin >> t;
        int flag = 1;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                flag = 0;
                for(int j = i + 1; j < n; j++)
                {
                    if(s[i] == s[j])
                    {
                        ans.push_back({j, i});
                        s[j] = t[i];
                        t[i] = s[i];
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0)
                {
                    for(int j = i + 1; j < n; j++)
                    {
                        if(s[i] == t[j])
                        {
                            ans.push_back({j, j});
                            t[j] = s[j];
                            s[j] = s[i];
                            ans.push_back({j, i});
                            s[j] = t[i];
                            t[i] = s[i];
                            flag = 1;
                            break;
                        }
                    }
                }
                if(!flag)
                    break;
            }
        }
        if(!flag)
            cout << "No\n";
        else
        {
            cout << "Yes\n";
            cout << ans.size() << "\n";
            for(auto x : ans)
                cout << x.first + 1 << " " << x.second + 1<< "\n";
        }
    }
}
