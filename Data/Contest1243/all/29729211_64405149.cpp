#include <bits/stdc++.h>

using namespace std;
int main()
{
    int k;
    cin >> k;
    while(k --)
    {
        int n;
        cin >> n;
        map<char , int> mp;
        string s1 , s2;
        cin >> s1 >> s2;
        for(int i = 0; i < s1.size(); i ++)
        {
            mp[s1[i]] ++;
        }
        for(int i = 0; i < s2.size(); i ++)
        {
            mp[s2[i]] ++;
        }
        int h = 0;
        for(auto it : mp)
        {
            if(it.second % 2 != 0)
            {
                cout << "No\n";
                h = 1;
                break;
            }
        }
        if(h) continue;
        vector<pair<int , int> > ans;
        for(int i = 0; i < s1.size() - 1; i ++)
        {
            if(s1[i] == s2[i]) continue;
            bool c2 = 1;
            for(int j = i + 1; j < s1.size(); j ++)
            {
                if(s1[i] == s1[j])
                {
                    c2 = 0;
                    ans.push_back({j , i});
                    s1[j] = s2[i];
                    break;
                }
            }
            if(c2)
            {
                for(int j = i; j < s2.size(); j ++)
                {
                    if(s1[i] == s2[j])
                    {
                        ans.push_back({i + 1 , j});
                        ans.push_back({i + 1 , i});
                        s2[j] = s1[i + 1];
                        s1[i + 1] = s2[i];
                        break;
                    }
                }
            }
        }
        cout << "Yes\n";
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i ++)
        {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }
    }
    return 0;
}



