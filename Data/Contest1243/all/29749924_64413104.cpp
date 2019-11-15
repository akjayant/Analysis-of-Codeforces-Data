#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define mod 1000000007
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define Find find_by_order
#define Pos order_of_key
#define N 1000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        
        ll vis[26];
        for(int i=0;i<26;i++) vis[i]=0;
        for(int i=0;i<n;i++) 
        {
            vis[s1[i]-'a']++;
            vis[s2[i]-'a']++;
        }
        
        ll x=0;
        for(int i=0;i<26;i++)
        {
            if((vis[i]%2)!=0)
            {
                x=1;
            }
        }
        
        if(x==1) 
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
        
        vector<pair<ll,ll>> v;
        
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i]) continue;
            
            for(int j=i+1;j<n;j++)
            {
                if(s1[i]==s1[j])
                {
                    v.pb({j+1,i+1});
                    swap(s2[i],s1[j]);
                    break;
                }
            }
            if(s1[i]==s2[i]) continue;
            for(int j=i+1;j<n;j++) 
            {
                if(s1[i]==s2[j])
                {
                    v.pb({j+1,j+1});
                    v.pb({j+1,i+1});
                    swap(s1[j],s2[j]);
                    swap(s1[j],s2[i]);
                    break;
                }
            }
        }
        cout<<v.size()<<"\n";
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
    }
}