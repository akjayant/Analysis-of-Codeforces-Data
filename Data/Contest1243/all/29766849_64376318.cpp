#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back 
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define ld long double
#define int long long int 
#define F first 
#define S second
signed main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.pb(x);
        }
        sort(all(a),greater<int>());
        int ans;
        for(int i=0;i<n;i++)
        {
            if(i+1<=a[i])
            {
               ans = i+1;
            }
        }
        cout<<ans<<"\n";
    }
}