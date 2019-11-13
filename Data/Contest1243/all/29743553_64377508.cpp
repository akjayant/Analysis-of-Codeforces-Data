
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>t;
    while(t--)
    {
        string s,ss,sa,sb;
        cin>>n>>s>>ss;
        sa="";
        sb="";
        for(i=0; i<n; i++)
        {
            if(s[i]!=ss[i])
            {
                sa.push_back(s[i]);
                sb.push_back(ss[i]);
            }
        }
        if(sa.size()==0)
        {
            cout<<"Yes\n";
        }
        else if(sa.size()==1)
        {
            if(sa[0]==sb[0])
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        else if(sa.size()==2)
        {
            if(sa[0]==sa[1]&&sb[1]==sb[0])
            {
                cout<<"Yes\n";
            }
            else
                cout<<"No\n";
        }
        else
            cout<<"No\n";

    }
    return 0;
}
