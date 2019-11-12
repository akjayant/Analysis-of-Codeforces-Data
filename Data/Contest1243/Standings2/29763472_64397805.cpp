#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;


int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(false);
    int k;
    cin >> k;
    for(int j=0;j<k;j++)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        vector<pair<int,int>> out;
        vector<int> al(27,0);
        for(int i=0;i<n;i++)
        {
            al[s[i]-'a']++;
            al[t[i]-'a']++;
        }
        bool f = true;
        for(int i=0;i<27;i++)
        {
            if(al[i]%2 == 1)
                f = false;
        }
        if(!f)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
            for(int i=0;i<n;i++)
            {
                char c = s[i];
                if(c == t[i])
                    continue;
                f = false;
                for(int j=i+1;j<n;j++)
                {
                    if(s[j] == c)
                    {
                        swap(s[j],t[i]);
                        out.push_back({j,i});
                        f = true;
                        break;
                    }
                }
                if(f)
                    continue;
                for(int j=i+1;j<n;j++)
                {
                    if(t[j] == c)
                    {
                        swap(t[j],s[j]);
                        out.push_back({j,j});
                        swap(s[j],t[i]);
                        out.push_back({j,i});
                        break;
                    }
                }
            }
            cout << out.size() << '\n';
            for(int i=0;i<out.size();i++)
            {
                cout << out[i].x+1 << ' ' << out[i].y+1 <<'\n';
            }

        }
    }

    return 0;
}
