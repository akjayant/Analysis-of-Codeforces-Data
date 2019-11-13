#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int k;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        string s,t;

        bool possible = true;

        cin >> s;
        cin >> t;

        int numc[509];

        for (int i = 1; i <= 500; i++) numc[i] = 0;

        for (int i = 0; i < n; i++)
        {
            numc[s[i]]++;
            numc[t[i]]++;
        }

        for (char c = 'a'; c <= 'z'; c++)
            if (numc[c]%2 == 1)
                possible = false;

        if (possible)
        {
            cout << "Yes" << endl;
            int m = 0;
            vector<pair<int,int> > res;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == t[i]) continue;

                bool found = false;

                for (int j = i+1; j < n; j++)
                {
                    if (!found && s[i] == s[j])
                    {
                        found = true;
                        res.push_back(make_pair(j+1,i+1));

                        char tmp = s[j];
                        s[j] = t[i];
                        t[i] = tmp;

                        //cout << s << endl << t << endl;
                    }
                }

                if (!found)
                {
                    for (int j = i+1; j < n; j++)
                    {
                        if (!found && s[i] == t[j])
                        {
                            found = true;
                            res.push_back(make_pair(i+2,j+1));
                            res.push_back(make_pair(i+2,i+1));
                            //cout << i+2 << ' ' << j+1 << endl;
                            //cout << i+2 << ' ' << i+1 << endl;

                            char tmp1 = s[i+1];

                            s[i+1] = t[i];
                            t[i] = t[j];
                            t[j] = tmp1;

                            //cout << s << endl << t << endl;
                        }
                    }
                }
            }

            m = res.size();

            cout << m << endl;

            for (int i = 0; i < m; i++) cout << res[i].first << ' ' << res[i].second << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
