#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define mod 1000000007
#define pii pair <long long,long long>

using namespace std;
string s;
vector <int> ans;
int res=1,dem=0,f[100005];
main()
{
    cin>>s;
    s=' '+s;
    s=s+' ';
    f[1]=1;
    f[2]=2;
    for(int i=0;i<s.size();i++)
        if(s[i]=='w'||s[i]=='m')
    {
        cout<<0;
        return 0;
    }
    for(int i=3;i<=100000;i++)
        f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='u'&&s[i-1]!='u')
        {
            dem=1;
        }
        else if(s[i]=='u'&&s[i-1]=='u')
        {
            dem++;
        }
        else
        {
            if(dem!=0)
                ans.push_back(dem);
                dem=0;
        }
    }
       for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='n'&&s[i-1]!='n')
        {
            dem=1;
        }
        else if(s[i]=='n'&&s[i-1]=='n')
        {
            dem++;
        }
        else
        {
            if(dem!=0)
                ans.push_back(dem);
            dem=0;
        }
    }
    for(int i=0;i<ans.size();i++)
        res=(res*f[ans[i]])%mod;
        cout<<res;
}
