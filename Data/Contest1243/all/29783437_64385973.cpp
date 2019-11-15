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
        string s, t;
        cin>>s>>t;
        map<pair<char, char>, int> mp;
        for(int i=0; i<n; i++)
        {
            if(s[i]!=t[i])
            {
                mp[{s[i],t[i]}]++;
            }
        }
        if(mp.size()==1)
        {
            if(mp.begin()->second==2)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    
    
    return 0; 
} 