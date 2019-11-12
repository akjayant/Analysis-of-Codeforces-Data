#include <bits/stdc++.h>

#define pii pair <int, int>
#define mp make_pair
#define f first
#define s second

using namespace std;

int q, n, i, j;
int prez[30];

vector <pii> ans;
string s1, s2;

int main()
{
    cin >> q;
    while(q--)
    {
        cin >> n >> s1 >> s2;

        memset(prez, 0, sizeof(prez));

        for(auto it : s1)
            prez[int(it - 'a')] ++;
        for(auto it : s2)
            prez[int(it - 'a')] ++;

        for(i=0; i<26; i++)
            if(prez[i] % 2 == 1)
                break;

        if(i<26) cout << "No\n";
        else
        {
            ans.clear();
            for(i=0; i<n; i++)
            {
                if(s1[i] == s2[i]) continue;

                for(j=i+1; j<n; j++)
                    if(s1[j] == s1[i]) break;
                if(j < n)
                {
                    ans.push_back(mp(j, i));
                    swap(s1[j], s2[i]);
                }
                else
                {
                    for(j=i+1; j<n; j++)
                        if(s2[j] == s1[i]) break;
                    if(j >= n)
                    {
                        cout << "No\n";
                        break;
                    }
                    else
                    {
                        ans.push_back(mp(j, j));
                        swap(s1[j], s2[j]);
                        ans.push_back(mp(j, i));
                        swap(s1[j], s2[i]);
                    }
                }
            }

            if(i == n)
            {
                cout << "Yes\n";
                cout << ans.size() << '\n';
                for(auto it : ans)
                    cout << it.f + 1 << " " << it.s + 1 << '\n';
            }

        }
    }
    return 0;
}
