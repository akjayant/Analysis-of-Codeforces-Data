//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n;
string ss1;
int r,p,s;
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>r>>p>>s>>ss1;
        int r1=0,p1=0,s1=0;
        for(int i=0;i<ss1.length();i++)
            if(ss1[i]=='R')
                r1++;
            else if(ss1[i]=='P')
                p1++;
            else
                s1++;
        int count=0;
        if(r1>=p)
        {
            count+=p;
        }
        else
        {
            count+=r1;
        }
        if(p1>=s)
        {
            count+=s;
        }
        else
        {
            count+=p1;
        }
        if(s1>=r)
        {
            count+=r;
        }
        else
        {
            count+=s1;
        }
        if(count*2>=n)
            cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
            continue;
        }
        string ans="";
        for(int i=0;i<ss1.length();i++)
        {
            if(ss1[i]=='R')
            {
                if(p>0)
                {
                    ans+='P';
                    p--;
                }
                else
                    ans+='F';
            }
            if(ss1[i]=='P')
            {
                if(s>0)
                {
                    ans+='S';
                    s--;
                }
                else
                    ans+='F';
            }
            if(ss1[i]=='S')
            {
                if(r>0)
                {
                    ans+='R';
                    r--;
                }
                else
                    ans+='F';
            }
        }
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]=='F')
            {
                if(r>0)
                {
                    ans[i]='R';
                    r--;
                }
                else if(p>0)
                {
                    ans[i]='P';
                    p--;
                }
                else if(s>0)
                {
                    ans[i]='S';
                    s--;
                }
            }
        }
        cout<<ans<<endl;
    }
}