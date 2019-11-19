#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                ans=max(ans,2*i+2);
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
                ans=max(ans,2*(n-i));
        }
        ans=max(ans,n);
        cout<<ans<<'\n';
    }
}

