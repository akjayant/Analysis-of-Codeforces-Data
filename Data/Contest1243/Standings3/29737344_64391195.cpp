#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n,i,j;
    cin>>n;
    string a, b;
    cin>>a>>b;
    vector <ll> cnt(26, 0);
    for(i=0; i<n; i++)
    {
        cnt[ a[i]-'a' ]++;
        cnt[ b[i]-'a' ]++;
    }
    for(i=0; i<26; i++)
        if (cnt[i]%2==1)
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;

    vector <pair<ll,ll> > ans;
    for(i=0; i<n; i++)
    {
        if (a[i] != b[i])
        {
            ll pos = -1;
            for(j = i+1; j<n; j++)
                {
                    if (b[j] == a[i])
                        pos = j;
                }
                if (pos !=-1)
                {
                    swap(b[pos], a[i+1]);
                    ans.push_back({i+1, pos});
                    swap(b[i], a[i+1]);
                    ans.push_back({i+1, i});
                }
                else
                //if (pos == -1)
                {
                    for(j = i+1; j<n; j++)
                        if (a[j] == a[i])
                        pos = j;
                        swap(b[i], a[pos]);
                        ans.push_back({pos, i});
                }
        }
    }
    cout<<ans.size()<<endl;
    for(i=0; i<ans.size(); i++)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
        solve();
    return 0;
}
