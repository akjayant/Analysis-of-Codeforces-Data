#include <bits/stdc++.h> 
using namespace std; 
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int32_t main() 
{ 
    IOS;
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==t[i])
                continue;
            for(int k=i+1;k<n;k++)
            {
                if(s[k]==t[k])
                    continue;
                if(s[k]==s[i])
                {
                    swap(s[k],t[i]);
                    v.push_back({k,i});
                    break;
                }
                if(t[k]==s[i])
                {
                    swap(s[k],t[k]);
                    v.push_back({k,k});
                    swap(s[k],t[i]);
                    v.push_back({k,i});
                    break;
                }
            }
        }
        if(s==t)
        {
            cout<<"Yes\n";
            cout<<v.size()<<endl;
            for(auto &it:v)
                cout<<it.first+1<<" "<<it.second+1<<endl;
        }
        else
            cout<<"No\n";
    }
    return 0; 
} 