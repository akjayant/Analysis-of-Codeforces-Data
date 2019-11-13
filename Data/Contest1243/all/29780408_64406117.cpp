#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool is_prime(ll n)
{

        return 1;
    return 0;
}

int find(char c, string s, int i);

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector <bool> base(26, 0);
        vector <bool> symbol(26, 0);
        map <int, int> m1;
        map <int, int> m2;
        string s, t;
        cin >> s >> t;
        for (int i=0; i<n; ++i)
        {
            symbol[s[i]-'a'] = symbol[s[i]-'a']^1;
            symbol[t[i]-'a'] = symbol[t[i]-'a']^1;
        }
        if (base != symbol)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            vector <int> out;
            for (int i=0; i<n; ++i)
            {
                if (s[i] == t[i])
                    continue;
                int idx = find(s[i], s, i+1);
                if (idx != -1)
                {
                    char temp = s[idx];
                    s[idx] = t[i];
                    t[i] = temp;
                    out.push_back(idx+1);
                    out.push_back(i+1);
                    continue;
                }

                idx = find(s[i], t, i);
                char temp = s[i+1];
                s[i+1] = t[idx];
                t[idx] = temp;
                temp = s[i+1];
                s[i+1] = t[i];
                t[i] = temp;
                out.push_back(i+2);
                out.push_back(idx+1);
                out.push_back(i+2);
                out.push_back(i+1);
            }
            cout << out.size()/2 << "\n";
            for (int i=0; i<out.size(); ++i)
            {
                if (i%2)
                    cout << out[i] << "\n";
                else
                    cout << out[i] << " ";
            }
        }

    }

    return 0;
}

int find(char c, string s, int i)
{
    for (; i<s.size(); ++i)
        if (s[i] == c)
            return i;
    return -1;
}









