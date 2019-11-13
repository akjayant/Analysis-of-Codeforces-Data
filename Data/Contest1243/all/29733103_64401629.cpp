#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pii 3.14
#define mod (ll)(1000000007)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pi pair<int,int>
#define N (ll)(1e6+5)

void solve()
{
    ll n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;


    ll cnt[26]={0};

    for(int i=0;i<n;i++)
    {
        cnt[s1[i] - 'a']++;
        cnt[s2[i] - 'a']++;
    }

    for(int i=0;i<26;i++)
    {
        if(cnt[i]&1)
        {
            cout<<"No\n";
            return;
        }
    }

    ll ans = 0;
    vector<pair<ll ,ll > >v;

    for(int i=0;i<n;i++)
    {
        if(s1[i] == s2[i])
            continue;
        char c1 = s1[i];
        int k = 0;
        for(int j=i+1;j<n;j++)
        {

            if(s1[j] == c1)
            {
                k = -1;
                ans++;
                v.push_back({j+1,i+1});
                swap(s1[j] , s2[i]);
                break;
            }

            if(s2[j] == c1)
            {
                k = j;
                break;
            }
        }

        if(k > 0){

        ans += 2;
        v.push_back({k+1 , k+1});
        v.push_back({k+1 , i+1});
        swap(s1[k] , s2[k]);
        swap(s1[k] , s2[i]);
        }

        if(s1 == s2)
            break;

    }

    if(ans > 2*n)
    {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    cout<<ans<<endl;
    for(auto el : v)
        cout<<el.first<<" "<<el.second<<endl;

}


int main()
{
    fio;
    ll t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

}
