#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<map>
#include<cmath>
#include<queue>

using namespace std;

#define int long long
#define forn for (int i=0; i<n; i++)
#define form for (int i=0; i<m; i++)
#define fornj for (int j=0; j<n; j++)
#define formj for (int j=0; j<m; j++)
#define edge l[i]--; r[i]--; d[l[i]].push_back(r[i]); d[r[i]].push_back(l[i]);

void write(const vector<int> &a)
{
    for (auto i:a)
    {
        cout<<i<<" ";
    }
}

set<int> t1[26];
set<int> t2[26];

vector<pair<int, int> > ans;

int32_t main()
{
    int q;
    cin>>q;
    while (q--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        ans.clear();
        for (int i=0; i<26; i++)
        {
            t1[i].clear();
            t2[i].clear();
        }
        for (int i=0; i<n; i++)
        {
            t1[s1[i]-'a'].insert(i);
            t2[s2[i]-'a'].insert(i);
        }
        bool can=false;
        for (int i=0; i<26; i++)
        {
            if ((t1[i].size()+t2[i].size())%2!=0)
            {
                can=true;
            }
        }
        if (can)
        {
            cout<<"No"<<'\n';
            continue;
        }
        for (int i=0; i<n-1; i++)
        {
            t1[s1[i]-'a'].erase(i);
            t2[s2[i]-'a'].erase(i);
            if (s1[i]==s2[i]) continue;
            if (t1[s1[i]-'a'].size()>0)
            {
                int l=(*t1[s1[i]-'a'].begin());
                t1[s1[l]-'a'].erase(l);
                t2[s2[i]-'a'].erase(i);
                ans.push_back({l,i});
                swap(s1[l],s2[i]);
                t1[s1[l]-'a'].insert(l);
                //t2[s2[i]-'a'].insert(i);
                //cout<<l<<" "<<s1[i]<<endl;
            }
            else
            {
                int l=(*t2[s1[i]-'a'].begin());
                ans.push_back({l,l});
                t1[s1[l]-'a'].erase(l);
                t2[s2[l]-'a'].erase(l);
                swap(s1[l],s2[l]);
                t1[s1[l]-'a'].insert(l);
                t2[s2[l]-'a'].insert(l);
                ans.push_back({l,i});
                t1[s1[l]-'a'].erase(l);
                t2[s2[i]-'a'].erase(i);
                swap(s1[l],s2[i]);
                t1[s1[l]-'a'].insert(l);
                //t2[s2[i]-'a'].insert(i);
                //cout<<l<<endl;
            }
            if (s1==s2) break;
        }
        if (s1!=s2)
        {
            cout<<"No"<<'\n';
            continue;
        }
        cout<<"Yes"<<'\n';
        cout<<ans.size()<<'\n';
        for (auto i:ans)
        {
            cout<<i.first+1<<" "<<i.second+1<<'\n';
        }
    }
}
