#include <bits/stdc++.h>

using namespace std;

int n, k;
string s, t;
vector <pair <int,int> > res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cin >> k;
    while (k--)
    {
        cin >> n;
        cin >> s;
        cin >> t;
        res.clear();
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]){
                for (int j = i + 1; j < n; j++)
                    if (t[i] == t[j])
                    {
                        res.push_back({i,j});
                        swap(s[i],t[j]);
                        break;
                    }
                    else if (s[j] == t[i]){
                        res.push_back({i,i});
                        swap(s[i],t[i]);
                        res.push_back({j,i});
                        swap(s[j],t[i]);
                        break;
                    }
                    else if (s[i] == t[j]){
                        res.push_back({i,i});
                        swap(s[i],t[i]);
                        res.push_back({i,j});
                        swap(s[i],t[j]);
                        break;
                    }
            }
        if (s == t)
        {
            cout << "Yes\n";
            cout << res.size() << "\n";
            for (int i = 0; i < res.size(); i++)
                cout<< res[i].first + 1 << " " << res[i].second + 1 << "\n";
        }
        else
            cout << "No\n";
    }
}
