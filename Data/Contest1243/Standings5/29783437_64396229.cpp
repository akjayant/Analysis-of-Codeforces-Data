#include <bits/stdc++.h> 
using namespace std; 
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int32_t main() 
{ 
    IOS;
    
    int n;
    cin>>n;
    set<int> s;
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            s.insert(i);
        }
    }
    if(n>1)
        s.insert(n);
    
    if(s.size()>1)
    {
        cout<<"1";
        return 0;
    }
    cout<<*(s.begin());
    return 0; 
} 