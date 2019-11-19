#include<bits/stdc++.h>
//#include <numeric>
using namespace std;
#define int long long int
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,flag=0;;
        cin>>n;
        string s;
        cin>>s;
        int x=n,y=0;
        for(i=0;i<n;i++)
        {
             if(s[i]=='1')
             {
                x=i;
                flag=1;
                break;
             }
        }
        for(i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                y=i;
                flag=1;
                break;
            }
        }
        int ans=n;
        if(flag!=0)
            ans=max(2*(n-x),2*(y+1));
        cout<<ans<<"\n";
    }
}