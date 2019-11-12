#include <bits/stdc++.h>
using namespace std;
int n,q,cnt[300];
string s,t;
vector <int> v[300];
int main()
{
    cin >>q;
    while (q--)
    {
        cin >>n>>s>>t;
        memset(cnt,0,sizeof cnt);
        for (int i=0;i<300;i++)
        {
            if (!v[i].empty())
                v[i].clear();
        }
        for (int i=0;i<n;i++)
        {
            cnt[s[i]]++;
            cnt[t[i]]++;
        }
        bool yes=true;
        int cur=-1;
        for (int i=0;i<n;i++)
        {
            if (t[i]!=s[i])
            {
                if (cur>n)
                    yes=false;
                else if (cur==-1)
                    cur=i;
                else
                {
                    swap(s[i],t[cur]);
                    cur=1340134;
                }
            }
        }
        if (!yes||s!=t)
            cout <<"No\n";
        else
            cout <<"Yes\n";
    }
    return 0;
}
