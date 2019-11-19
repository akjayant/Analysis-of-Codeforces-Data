#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t, n ;
string s;
int main()
{
    IO
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int ans=n;
        for(int i=1; i<=n; i++)
            if(s[i-1]=='1')
            {
                ans=max(ans,i*2);
            }
        reverse(s.begin(),s.end());
        for(int i=1; i<=n; i++)
            if(s[i-1]=='1')
            {
                ans=max(ans,i*2);
            }
        cout<<ans<<endl;
    }
}
