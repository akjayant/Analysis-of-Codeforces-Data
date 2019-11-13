#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    int k;
    cin >> k;
    for(int j=0;j<k;j++)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int x1 = -1,x2 = -1;
        bool f = true;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                if(x1 == -1)
                    x1 = i;
                else if(x2 == -1)
                    x2 = i;
                else
                {
                    f = false;
                    break;
                }
            }
        }
        if(!f)
        {
            cout << "no\n";
        }
        else
        {
           // cout << "ok";
            if(s[x1] == s[x2] && t[x2] == t[x1])
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }

    return 0;
}
