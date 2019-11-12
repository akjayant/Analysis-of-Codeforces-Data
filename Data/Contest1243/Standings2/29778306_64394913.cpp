#include <bits/stdc++.h>
using namespace std;

#define maxn 100

int ntest;
string s, t;
char ss[maxn];
char tt[maxn];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> ntest;
    for (int test = 1; test <= ntest; test++)
    {
        cin >> n;
        cin >> s >> t;
        for (int i = 1; i <= n; i++)
        {
            ss[i] = s[i - 1];
            tt[i] = t[i - 1];
        }

        bool ok = true;
        vector< pair<int, int> > ans;
        for (int i = 1; i <= n; i++)
        {
            if (ss[i] == tt[i]) continue;
            int id = -1;
            for (int j = i + 1; j <= n; j++)
                if (ss[i] == tt[j])
                {
                    id = j;
                    break;
                }
            if (id != -1)
            {
                ans.push_back({i + 1, id});
                swap(ss[i + 1], tt[id]);
                ans.push_back({i + 1, i});
                swap(ss[i + 1], tt[i]);
                continue;
            }

            for (int j = i + 1; j <= n; j++)
                if (ss[i] == ss[j])
                {
                    id = j;
                    break;
                }
            if (id != -1)
            {
                ans.push_back({id, i});
                swap(ss[id], tt[i]);
                continue;
            }
            ok = false;
            break;
        }
        if (ok == false) cout << "No" << endl;
        else
        {
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}
