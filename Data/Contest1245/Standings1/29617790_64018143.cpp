/// ANTI_LIGHT

#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define f first
#define s second

const int maxn=1e5+100;
const int mod=1e9+7;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,p,s;
        string hd;
        cin>>n>>r>>p>>s;
        cin>>hd;

        string ans="";
        int tem=0;
        for(int i=0;i<hd.size();i++)
        {
            char x=hd[i];
            if(x=='R')
            {
                if(p)
                {
                    p--;
                    ans=ans+"P";
                    tem++;
                }
                else
                    ans=ans+"*";
            }
            else if(x=='P')
            {
                if(s)
                {
                    s--;
                    ans=ans+"S";
                    tem++;
                }
                else
                    ans=ans+"*";
            }
            else if(x=='S')
            {
                if(r)
                {
                    r--;
                    ans=ans+"R";
                    tem++;
                }
                else
                    ans=ans+"*";
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]!='*')
                continue;
            if(r)
            {
                ans[i]='R';
                r--;
                continue;
            }
            if(p)
            {
                ans[i]='P';
                p--;
                continue;
            }
            if(s)
            {
                ans[i]='S';
                s--;
                continue;
            }
        }
        if(tem>=(n+1)/2)
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }

    return 0;
}
