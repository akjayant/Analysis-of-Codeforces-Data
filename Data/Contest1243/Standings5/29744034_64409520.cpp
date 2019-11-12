#include <bits/stdc++.h>
#define INF 1e18
#define M 1000000007
#define ll long long
using namespace std;

int find(string s, int n, int x, char ch)
{
    for(int i = x; i < n; i++)
    {
        if(s[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

void swap(string &s, string &t, int i, int j)
{
    char ch = s[i];
    s[i] = t[j];
    t[j] = ch;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        bool ans = true;
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        map <char, int> m;
        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;
            m[t[i]]++;
        }
        for(auto p: m)
        {
            if(p.second & 1)
            {
                ans = false;
                break;
            }
        }
        if(ans == false)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
            vector < pair <int, int> > v;
            for(int i = 0; i < n; i++)
            {
                if(s[i] == t[i])
                {
                    continue;
                }
                int x = find(s, n, i + 1, s[i]);
                if(x != -1)
                {
                    swap(s, t, x, i);
                    v.push_back(make_pair(x + 1, i + 1));
                }
                else
                {
                    x = find(t, n, i + 1, s[i]);
                    swap(s, t, x, x);
                    swap(s, t, x, i);
                    v.push_back(make_pair(x + 1, x + 1));
                    v.push_back(make_pair(x + 1, i + 1));
                }
            }
            int sz = v.size();
            cout << sz << endl;
            for(int i = 0; i < sz; i++)
            {
                cout << v[i].first << " " << v[i].second << endl;
            }
        }
    }
}