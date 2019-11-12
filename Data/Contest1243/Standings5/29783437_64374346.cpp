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
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int res=0;
        sort(v.begin(),v.end());
        for(int i=1;i<=1000;i++)
        {
            int temp=v.end()-lower_bound(v.begin(),v.end(),i);
            if(temp>=i)
                res=i;
        }
        cout<<res<<endl;
    }
    
    
    return 0; 
} 