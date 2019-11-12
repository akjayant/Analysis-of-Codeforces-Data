#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define mod 1000000007
#define bitcount(x) __builtin_popcount(x)
#define all(v) (v).begin(), (v).end()
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;
inline int add(int a, int b, int p = mod){ int c = a + b; if(c >= p) c -= p; return c; }
inline int sub(int a, int b, int p = mod){ int c = a - b; if(c < 0) c += p; return c; }
inline int mul(int a, int b, int p = mod){ return (a * (long long)1 * b) % p; }

using namespace __gnu_pbds;
template<class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//methods: find_by_order(k); & order_of_key(k);
//To make it an ordered_multiset, use pairs of (value, time_of_insertion)
//to distinguish values which are similar

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;



void Onigiri()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
   
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[s[i]-'a']++;
        mp[t[i]-'a']++;
    }
    for(auto x:mp)
    {
        if(x.second%2!=0)
        {
            cout<<"No"<<endl;return;
        }
    }
     vector< pair <int,int> > ans;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
        {
            flag=0;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                {
                    flag=1;
                    ans.push_back(make_pair(j,i));
                    swap(s[j],t[i]);
                    break;
                }
            }
            if(flag==0)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(t[j]==s[i])
                    {
                        flag=1;
                        ans.push_back(make_pair(j,j));
                        swap(t[j],s[j]);
                        ans.push_back(make_pair(j,i));
                        swap(s[j],t[i]);
                        break;
                    }
                }
            }

        }
        else continue;
    }
    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<(ans[i].first+1LL)<<" "<<(ans[i].second+1LL)<<endl;
    }


    
}

signed main()
{

ios_base::sync_with_stdio(false);cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        Onigiri();
       // cout<<endl;
    }
    return 0;
}