
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<long long>v[3000];
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        if(s[0]=='1'||s[n-1]=='1')
        {
            cout<<2*n<<'\n';
            continue;
        }
        a=0;
        b=0;
        for(i=0; i<n; i++)
        {
            if(s[i]=='0')
                a++;
            else
                break;
        }
        for(i=n-1; i>=0; i--)
        {
            if(s[i]=='0')
                b++;
            else
                break;
        }
        a=min(a,b);
        f=2*n-2*a;
        f=max(n,f);
        cout<<f<<'\n';
    }
    return 0;
}
