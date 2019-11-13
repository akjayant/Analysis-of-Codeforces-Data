//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int maxn = 100 * 1001;
const int mod = 1e9+7;

ll a[maxn], n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int q; cin>> q;
    while(q--)
    {
        cin>> n;
        string s, t; cin>> s >> t;
        set<pair<int,int>> idx[30];
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            int x = s[i] - 'a';
            int xx = t[i] - 'a';
            idx[x].insert({i,0});
            idx[xx].insert({i,1});
            mp[x]++;
            mp[xx]++;
        }

        bool F = 0;
        for(int i = 0; i < 26; i++)
            if(mp[i]&1)
                F = 1;
        if(F){
            cout<<"No\n"; continue;
        }

        vector<pair<int,int>> ans;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                int x = t[i] - 'a';
                idx[x].erase({i,1});
                pair<int,int> y = *idx[x].begin();
                if(y.second == 0)
                {
                    int xx = s[i] - 'a';
                    idx[xx].erase({i,0});
                    idx[xx].insert({y.first,0});
                    idx[x].erase({y.first,0});
                    swap(s[i],s[y.first]);
                    ans.push_back({i,i});
                    ans.push_back({y.first,i});
                }
                else
                {
                    idx[x].erase({y.first,1});
                    int xx = s[i] - 'a';
                    swap(s[i],t[y.first]);
                    idx[xx].erase({i,0});
                    idx[xx].insert({y.first,1});
                    ans.push_back({i,y.first});
                }
            }
            else
            {
                int x = s[i] - 'a';
                int xx = t[i] - 'a';
                idx[x].erase({i,0});
                idx[xx].erase({i,1});
            }
        }
        cout<<"Yes\n";
        cout<< ans.size() <<"\n";
        for(auto x : ans)
            cout<< x.first+1 <<" "<< x.second+1 <<"\n";
    }
}
