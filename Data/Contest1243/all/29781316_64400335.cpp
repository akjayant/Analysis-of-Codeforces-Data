#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1006;
ll n, m, i, j, k, a, b, ans, v[N], q;
string s, t;
int main()
{
    cin>>q;
    while(q)
    {
        --q;
        cin>>n>>s>>t;
        vector<pair<ll,ll> > ans;
        for(i=0; i<n; i++)
            if(s[i]!=t[i])
            {
                int ok=0;
                for(j=i+1; j<n; j++)
                    if(s[i]==s[j])
                    {
                        swap(s[j],t[i]);
                        ans.push_back({j,i});
                        ok=1;
                        break;
                    }
                if(!ok)
                    for(j=i+1; j<n; j++)
                        if(t[i]==t[j])
                        {
                            swap(s[i],t[j]);
                            ans.push_back({i,j});
                            ok=1;
                            break;
                        }
                if(s[i]!=t[i])
                {
                    ok=0;
                    ans.push_back({i,i});
                    swap(s[i],t[i]);
                    for(j=i+1; j<n; j++)
                        if(s[i]==s[j])
                        {
                            swap(s[j],t[i]);
                            ans.push_back({j,i});
                            ok=1;
                            break;
                        }
                    if(!ok)
                        for(j=i+1; j<n; j++)
                            if(t[i]==t[j])
                            {
                                swap(s[i],t[j]);
                                ans.push_back({i,j});
                                ok=1;
                                break;
                            }
                }
            }
        if(s!=t)
            cout<<"No\n";
        else
        {
            cout<<"Yes\n";
            cout<<ans.size()<<'\n';
            for(i=0; i<ans.size(); i++)
                cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';
        }
    }
    return 0;
}
