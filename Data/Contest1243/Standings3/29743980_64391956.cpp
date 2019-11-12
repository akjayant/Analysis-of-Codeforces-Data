#include <bits/stdc++.h>
using namespace std;
int n,q,cnt[300];
string s,t;
vector <pair<int,int> > ans;
int main()
{
    cin >>q;
    while (q--)
    {
        cin >>n>>s>>t;
        if (!ans.empty())
            ans.clear();
        for (int i=0;i<n;i++)
        {
            if (s[i]!=t[i])
            {
                for (int j=i+1;j<n;j++)
                {
                    if (s[i]==s[j])
                    {
                        ans.push_back({j,i});
                        swap(t[i],s[j]);
                        goto ss;
                    }
                }
                for (int j=i+1;j<n;j++)
                {
                    if (s[i]==t[j])
                    {
                        ans.push_back({j,j});
                        swap(t[j],s[j]);
                        ans.push_back({j,i});
                        swap(t[i],s[j]);
                        goto ss;
                    }
                }
            }
            ss:{}
        }
        if (s==t)
        {
            cout <<"Yes\n";
            cout <<ans.size()<<endl;
            for (int i=0;i<ans.size();i++)
            {
                cout <<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
            }
        }
        else
            cout <<"No\n";
    }
    return 0;
}
/*
if (b[s[i]].empty())
            {
                if (a[t[i]].empty())
                {
                    cout<<"No\n";
                    goto ss;
                }
                swap(s[i],t[a[t[i]].back()]);
                a[s[i]].pop_back();
                b[s[i]].push_back(b[t[i]].back());
                sort(b[s[i]].begin(),b[s[i]].end());
                reverse(b[s[i]].begin(),b[s[i]].end());
                b[t[i]].pop_back();
            }
*/
