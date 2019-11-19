#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int l=-1,r=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1'){l=i;break;}
        }
        if(l!=-1)l=max(n-l,l+1);
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1'){r=i;break;}
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')c++;
        }
        if(r!=-1)r=max(r+1,n-r);
        //cout<<l<<" "<<r<<" ";
        int ans=n;
        ans=max(ans,l*2);
        ans=max(ans,r*2);
        ans=max(ans,n+c);
        cout<<ans<<"\n";
    }
}
