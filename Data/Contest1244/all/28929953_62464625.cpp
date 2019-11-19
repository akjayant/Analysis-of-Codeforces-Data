
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
        cin>>a>>b>>c>>d>>k;
        p=9999999;
        for(i=0; i<=k; i++)
        {
            m=i;
            n=k-i;
            if(m*c>=a&&n*d>=b)
            {
                p=m;
                q=n;
            }
        }
        if(p>k)
            cout<<-1;
        else
            cout<<p<<' '<<q;
        cout<<"\n";
    }

    return 0;
}
