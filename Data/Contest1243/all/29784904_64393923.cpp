#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define fr(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define endl "\n"
#define fast std::ios_base::sync_with_stdio(false)
#define mod 1000000007
#define pi 3.14159265
void shikhar7s(int cas)
{
    int n,i;
    cin>>n;
    string s,t;
    cin>>s>>t;
    char c;
    int a[26]={0};
    fr(i,n)
    {
        a[s[i]-'a']++;
        a[t[i]-'a']++;
    }
    fr(i,26)
    {
        if(a[i]%2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    vector<pair<int,int> > ans;
    int j,f=0;
    fr(i,n-1)
    {
        if(s[i]!=t[i])
        {
            f=0;
            for(j=i+1;j<n;j++)
            {
                if(s[j]==s[i])
                {
                    f=1;
                    break;
                }
            }
            if(f)
            {
                ans.pb(mp(j+1,i+1));
                c=s[j];
                s[j]=t[i];
                t[i]=c;
            }
            else
            {
                for(j=i+1;j<n;j++)
                {
                    if(t[j]==s[i])
                        break;
                }
                ans.pb(mp(i+2,j+1));
                c=s[i+1];
                s[i+1]=t[j];
                t[j]=c;
                ans.pb(mp(i+2,i+1));
                c=s[i+1];
                s[i+1]=t[i];
                t[i]=c;
            }
        }
    }
    int anss=ans.size();
    cout<<anss<<endl;
    fr(i,anss)
    {
        cout<<ans[i].F<<" "<<ans[i].S<<endl;
    }
}
signed main()
{
    fast;
    int t=1;
    cin>>t;
    int cas=1;
    while(cas<=t)
    {
    shikhar7s(cas);
    cas++;
    }
    return 0;
}