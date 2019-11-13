#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pp pair<long long,long long>
#define f first
#define s second
vector <pp> res;
vector<ll> vec;
string s1,s2;
int main()
{
    ll t,n,i,j,k,l;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n;
        cin>>s1>>s2;
        for (i=0;i<n;i++)
        {
            if (s1[i]!=s2[i])
            {
                vec.pb(i);
            }
        }
        for (i=0;i<vec.size();i++)
        {
            if (s1[vec[i]]==s2[vec[i]])
                continue;
            for (j=i+1;j<vec.size();j++)
            {
                if (s1[vec[i]]==s1[vec[j]])
                {
                    res.pb(pp(vec[j],vec[i]));
                    char ch = s2[vec[i]];
                    s2[vec[i]]=s1[vec[j]];
                    s1[vec[j]]=ch;
                    break;
                }
                else if (s1[vec[i]]==s2[vec[j]])
                {
                    res.pb(pp(vec[j],vec[j]));
                    res.pb(pp(vec[j],vec[i]));
                    char ch = s2[vec[j]];
                    s2[vec[j]]=s1[vec[j]];
                    s1[vec[j]]=ch;
                    ch = s2[vec[i]];
                    s2[vec[i]]=s1[vec[j]];
                    s1[vec[j]]=ch;
                    break;
                }
            }
            if (j==vec.size())
                break;
        }
        if (s1==s2)
        {
            cout<<"Yes\n";
            cout<<res.size()<<'\n';
            for (i=0;i<res.size();i++)
                cout<<res[i].f+1<<' '<<res[i].s+1<<'\n';
        }
        else
            cout<<"No\n";
        vec.clear();
        res.clear();
    }
    return 0;
}