
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
        cin>>n;
        v.clear();
        for(i=0; i<n; i++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        f=0;
        a=0;
        for(i=n-1; i>=0; i--)
        {
            a++;
            b=min(a,v[i]);
            f=max(f,b);
        }
        cout<<f<<'\n';
    }
    return 0;
}
