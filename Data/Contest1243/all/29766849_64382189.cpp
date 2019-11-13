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
       string s,t;
       cin>>s>>t;
       int differ = 0;
       int aa=-1,bb=-1;
       for(int i=0;i<n;i++)
       {
            if(s[i]!=t[i])
            {
                differ++;
            }
            if(s[i]!=t[i] && aa==-1)
            {
                aa = i;
            }
            if(s[i]!=t[i] && aa!=-1)
                bb = i;
       }
       if(differ>=3)
       {
            cout<<"No\n";
       }
       else if(differ == 0)
        cout<<"Yes\n";
        else if(differ == 1)
        {
            cout<<"No\n";
        }
        else if(differ==2)
        {
            char tmp = s[aa];
            s[aa] = t[bb];
            t[bb] = tmp;
            if(s == t)
            {
                cout<<"Yes\n";
            }
            else
            {
                 char tmp = s[aa];
                    s[aa] = t[bb];
                    t[bb] = tmp;
                tmp = s[bb];
                s[bb] = t[aa];
                t[aa] = tmp;
                if(s == t)
                    cout<<"Yes\n";
                else cout<<"No\n";
            }
        }
        
    }
}