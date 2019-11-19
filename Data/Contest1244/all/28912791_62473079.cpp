#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        int ans=n;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1'){
                if( 2*(i+1)> ans)
                    ans=2*(i+1);
                if( 2*(s.length()-i) > ans)
                    ans=2*(s.length()-i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}